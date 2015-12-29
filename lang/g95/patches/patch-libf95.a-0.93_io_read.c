$NetBSD: patch-libf95.a-0.93_io_read.c,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/io/read.c.orig	2013-03-01 11:14:56.000000000 +0000
+++ libf95.a-0.93/io/read.c
@@ -102,7 +102,7 @@ void set_real(int value, void *dest, int
 
 #if HAVE_REAL_10
     case 10:
-	asm("fild %0\n"
+	asm("filds %0\n"
 	    "mov %1, %" EAX "\n"
 	    "fstpt (%" EAX ")\n" : : "m" (value), "m" (dest) : EAX);
 	break;
