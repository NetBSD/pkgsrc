$NetBSD: patch-Opcodes_cpumeter.c,v 1.1 2014/03/06 10:16:53 mrg Exp $

be best to patch this to use eg, getloadavg() or something not /proc.

--- Opcodes/cpumeter.c.orig	2014-01-07 08:53:48.000000000 -0800
+++ Opcodes/cpumeter.c	2014-02-12 23:36:40.000000000 -0800
@@ -16,7 +16,7 @@
  *
  */
 
-#if defined(__MACH__) || defined(LINUX)
+#if defined(__MACH__) || defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include "csoundCore.h"
 #include <sys/resource.h>
