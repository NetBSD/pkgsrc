$NetBSD: patch-Opcodes_cpumeter.c,v 1.3 2014/08/06 06:17:07 mrg Exp $

Add NetBSD and DragonFlyBSD support.

be best to patch this to use eg, getloadavg() or something not /proc.

--- Opcodes/cpumeter.c.orig	2014-05-04 04:49:41.000000000 -0700
+++ Opcodes/cpumeter.c	2014-08-04 22:19:34.000000000 -0700
@@ -17,7 +17,7 @@
  */
 
 // only available on Linux (no /proc/stat on OSX)
-#if defined(LINUX)
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include "csoundCore.h"
 #include <sys/resource.h>
