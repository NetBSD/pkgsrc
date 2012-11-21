$NetBSD: patch-src_modules_videostab_stab_estimate.c,v 1.1 2012/11/21 22:24:27 abs Exp $

* Add !defined(__NetBSD__) to a list of OS types #if

--- src/modules/videostab/stab/estimate.c.orig	2012-11-15 03:05:11.000000000 +0000
+++ src/modules/videostab/stab/estimate.c
@@ -18,7 +18,8 @@
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
-#if !defined(__DARWIN__) && !defined(__FreeBSD__) && !defined(WIN32)
+/* XXX should probably be "if defined..." not "if !defined..." */
+#if !defined(__DARWIN__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(WIN32)
 #include <values.h>
 #endif
 
