$NetBSD: patch-libf95.a-0.93_runtime_mutex.c,v 1.1 2016/09/28 15:34:54 maya Exp $

gcc on netbsd/mips rejects ll/sc as it targets mips1 which lacks
these instructions. tell it it's mips3 code. it will crash
at runtime for mips1 (unlikely to compile this package), but
makes it possible to build for newer mips.

--- libf95.a-0.93/runtime/mutex.c.orig	2008-09-17 03:45:13.000000000 +0000
+++ libf95.a-0.93/runtime/mutex.c
@@ -116,9 +116,12 @@ int old_val, temp;
 
     __asm__ __volatile__("   move %5, %2     \n"
 			 "1: move %2, %5     \n"
+			 "   .set push       \n"
+			 "   .set mips3      \n"
 			 "   ll   %0, %4     \n"
 			 "   bne  %0, %3, 2f \n"
 			 "   sc   %2, %1     \n"
+			 "   .set pop        \n"
 			 "   beqz %2, 1b     \n"
 			 "2:\n"
 			 : "=&r" (old_val), "=m" (*addr)
