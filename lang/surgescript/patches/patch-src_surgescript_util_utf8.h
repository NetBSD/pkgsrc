$NetBSD: patch-src_surgescript_util_utf8.h,v 1.1 2021/02/28 08:06:52 nia Exp $

This header file is included in various places without including the
<stdarg.h> prerequisite beforehand. Fix it the lazy way.

--- src/surgescript/util/utf8.h.orig	2021-01-22 18:42:07.000000000 +0000
+++ src/surgescript/util/utf8.h
@@ -6,6 +6,9 @@
 #ifndef UTF8_H
 #define UTF8_H
 
+#include <stdarg.h>
+#include <stdint.h>
+
 extern int locale_is_utf8;
 
 /* is c the start of a utf8 sequence? */
