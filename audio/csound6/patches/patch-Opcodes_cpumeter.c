$NetBSD: patch-Opcodes_cpumeter.c,v 1.4 2019/11/02 22:25:46 mrg Exp $

Add NetBSD and DragonFlyBSD support.

be best to patch this to use eg, getloadavg() or something not /proc.

--- Opcodes/cpumeter.c.orig	2019-07-12 14:54:19.000000000 -0700
+++ Opcodes/cpumeter.c	2019-10-29 13:44:20.487656938 -0700
@@ -36,7 +36,7 @@
 #include <float.h>
 
 // only available on Linux (no /proc/stat on OSX)
-#if defined(LINUX)
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 /*######  Miscellaneous global stuff  ####################################*/
 #define SMLBUFSIZ (512)
 #define TEST (0)
