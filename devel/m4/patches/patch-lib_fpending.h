$NetBSD: patch-lib_fpending.h,v 1.1 2013/11/01 09:49:20 ryoon Exp $

https://github.com/jrmarino/DPorts/blob/9d9256e3b72a1273339bce4b68878e64b6fadcde/devel/m4/dragonfly/patch-lib_fpending.h

--- lib/fpending.h.orig	2013-09-22 06:15:20.000000000 +0000
+++ lib/fpending.h
@@ -24,6 +24,8 @@
 # include <stdio_ext.h>
 #endif
 
+#ifndef __DragonFly__
 #ifndef __fpending
 size_t __fpending (FILE *);
 #endif
+#endif
