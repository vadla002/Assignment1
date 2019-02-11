/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
	printk(KERN_INFO "Loading the module");
	printk(KERN_INFO "The value of GOLDEN_RATIO_PRIME is %lu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "The value of jiffies is %lu\n", jiffies);
	printk(KERN_INFO "The value of HZ is %d\n", HZ);
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing the module");
	printk(KERN_INFO "The gcd value of 3300 & 24 is %lu\n", gcd(3300, 24));
	printk(KERN_INFO "The value of jiffies is %lu\n", jiffies);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

