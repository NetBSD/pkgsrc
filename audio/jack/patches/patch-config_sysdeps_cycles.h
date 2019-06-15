$NetBSD: patch-config_sysdeps_cycles.h,v 1.1 2019/06/15 08:21:32 adam Exp $

Add support for Alpha.

--- config/sysdeps/cycles.h.orig	2016-02-23 15:13:53.000000000 +0000
+++ config/sysdeps/cycles.h
@@ -19,6 +19,10 @@
 
 #include <config/cpu/powerpc/cycles.h>
 
+#elif defined(__alpha__)
+
+#include <config/cpu/alpha/cycles.h>
+
 #else
 
 #include <config/cpu/generic/cycles.h>
