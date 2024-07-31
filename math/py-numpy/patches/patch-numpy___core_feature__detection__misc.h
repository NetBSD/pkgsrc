$NetBSD: patch-numpy___core_feature__detection__misc.h,v 1.1 2024/07/31 18:11:24 adam Exp $

Do not use incorrect forward declaration on SunOS.

--- numpy/_core/feature_detection_misc.h.orig	2024-02-28 11:24:51.747334468 +0000
+++ numpy/_core/feature_detection_misc.h
@@ -1,4 +1,6 @@
 #include <stddef.h>
 
 int backtrace(void **, int);
+#ifndef __sun
 int madvise(void *, size_t, int);
+#endif
