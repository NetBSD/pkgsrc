$NetBSD: patch-lib_xsize.h,v 1.1 2011/02/12 01:58:55 obache Exp $

* SUA have both initypes.h and stdint.h, but SIZE_MAX is in stdint.h.

--- lib/xsize.h.orig	2006-06-28 13:39:29.000000000 +0000
+++ lib/xsize.h
@@ -26,7 +26,8 @@
 #include <limits.h>
 #if HAVE_INTTYPES_H
 # include <inttypes.h>
-#elif HAVE_STDINT_H
+#endif
+#if HAVE_STDINT_H
 # include <stdint.h>
 #endif
 
