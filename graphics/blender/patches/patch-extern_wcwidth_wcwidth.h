$NetBSD: patch-extern_wcwidth_wcwidth.h,v 1.1 2020/02/21 16:36:54 nia Exp $

NetBSD also does not have uchar.h.

--- extern/wcwidth/wcwidth.h.orig	2020-02-12 10:15:01.000000000 +0000
+++ extern/wcwidth/wcwidth.h
@@ -21,7 +21,7 @@
 #define __WCWIDTH_H__
 
 #ifndef __cplusplus
-#  if defined(__APPLE__)
+#  if defined(__APPLE__) || defined(__NetBSD__)
 /* The <uchar.h> standard header is missing on macOS. */
 #include <stddef.h>
 typedef unsigned int char32_t;
