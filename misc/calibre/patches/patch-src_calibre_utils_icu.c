$NetBSD: patch-src_calibre_utils_icu.c,v 1.2 2022/01/09 15:43:51 rhialto Exp $

Fix build with ICU 68.

--- src/calibre/utils/icu.c.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/utils/icu.c
@@ -4,6 +4,8 @@
 #define LOWER_CASE 1
 #define TITLE_CASE 2
 
+#define TRUE 1
+
 static PyObject* uchar_to_unicode(const UChar *src, int32_t len) {
     wchar_t *buf = NULL;
     PyObject *ans = NULL;
