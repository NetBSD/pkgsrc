$NetBSD: patch-libf95.a-0.93_intrinsics_random.c,v 1.1 2013/03/02 18:05:46 joerg Exp $

--- libf95.a-0.93/intrinsics/random.c.orig	2013-03-01 11:13:35.000000000 +0000
+++ libf95.a-0.93/intrinsics/random.c
@@ -208,7 +208,7 @@ int scale;
     harvest[0] = xorshf96();
     harvest[1] = xorshf96() & 0x7FFFFFFF;
 
-    asm("fild %0\n"
+    asm("filds %0\n"
 	"mov %1, %" EAX "\n"
 	"fildll (%" EAX ")\n"
 	"fscale\n"
