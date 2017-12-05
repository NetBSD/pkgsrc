$NetBSD: patch-fdtoverlay.c,v 1.1 2017/12/05 09:54:18 adam Exp $

alloca.h is not portable.

--- fdtoverlay.c.orig	2017-12-05 08:56:30.828684391 +0000
+++ fdtoverlay.c
@@ -26,7 +26,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __linux__
 #include <alloca.h>
+#endif
 #include <inttypes.h>
 
 #include <libfdt.h>
