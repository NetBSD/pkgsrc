$NetBSD: patch-include_text.h,v 1.1 2016/03/29 22:06:48 joerg Exp $

--- include/text.h.orig	2016-03-28 17:47:57.518957272 +0000
+++ include/text.h
@@ -111,7 +111,7 @@ extern "C" {
 #endif
 #include <libintl.h>
   char *csoundLocalizeString(const char *s)
-     __attribute__ ((format (printf, 1,0)));
+     __attribute__ ((format_arg (1)));
   /* This could be gettext but this indirection helps debugging */
 #define Str(x) csoundLocalizeString(x)
   void init_getstring(void*);
