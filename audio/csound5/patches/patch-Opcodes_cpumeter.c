$NetBSD: patch-Opcodes_cpumeter.c,v 1.1 2014/02/13 12:44:47 mrg Exp $

be best to patch this to use eg, getloadavg() or something not /proc.

--- Opcodes/cpumeter.c.orig	2013-01-07 04:49:34.000000000 -0800
+++ Opcodes/cpumeter.c	2014-02-12 22:31:00.000000000 -0800
@@ -16,7 +16,7 @@
  *
  */
 
-#if defined(__MACH__) || defined(LINUX) || defined(__HAIKU__)
+#if defined(__MACH__) || defined(LINUX) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include "csoundCore.h"
 #include <sys/resource.h>
