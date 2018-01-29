$NetBSD: patch-main.c,v 1.2 2018/01/29 13:55:30 maya Exp $

Disable one of the tests that causes reboots/hangs at setup
(XXX figure out why - use btflag and btrace to debug this)
Clang fix

--- main.c.orig	2013-08-10 02:01:58.000000000 +0000
+++ main.c
@@ -54,7 +54,7 @@ struct tseq tseq[] = {
 	{1, 32,  3,   6, 0, "[Moving inversions, 1s & 0s Parallel]  "},
 	{1, 32,  5,   3, 0, "[Moving inversions, 8 bit pattern]     "},
 	{1, 32,  6,  30, 0, "[Moving inversions, random pattern]    "},
-	{1, 32,  7,  81, 0, "[Block move]                           "}, 
+	//{1, 32,  7,  81, 0, "[Block move]                           "},
 	{1,  1,  8,   3, 0, "[Moving inversions, 32 bit pattern]    "}, 
 	{1, 32,  9,  48, 0, "[Random number sequence]               "},
   {1, 32, 10,   6, 0, "[Modulo 20, Random pattern]            "},
@@ -217,7 +217,11 @@ static void run_at(unsigned long addr, i
   spin_lock(&barr->mutex);   
 
 	/* Jump to the start address */
+#ifdef __clang__
+	asm volatile ("jmp *%0" : : "a" (ja));
+#else
 	goto *ja;
+#endif
 }
 
 /* Switch from the boot stack to the main stack. First the main stack
