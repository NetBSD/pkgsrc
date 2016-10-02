$NetBSD: patch-libf95.a-0.93_runtime_mutex.c,v 1.2 2016/10/02 23:26:40 maya Exp $

This package builds a gcc on netbsd/mips which defaults to o32 mips1
output, and then uses it to compile g95 - which then uses assembly that
is rejected for the chosen -mips1 by the linker.

set mips3 for this segment, it'll stop being rejected by the linker, but
will crash if anyone runs this code on actual mips1 (rare).

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
