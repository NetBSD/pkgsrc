$NetBSD: patch-fontforge_splinefont.h,v 1.1 2016/02/07 14:09:08 adam Exp $

NetBSD does not implement uselocale().

--- fontforge/splinefont.h.orig	2016-02-07 13:01:04.000000000 +0000
+++ fontforge/splinefont.h
@@ -3548,6 +3548,10 @@ char * delimit_null(const char * input, 
 
 #include "ustring.h"
 
+#ifdef __NetBSD__
+#define BAD_LOCALE_HACK
+#endif
+
 #ifdef _WIN32
 #define BAD_LOCALE_HACK
 typedef char* locale_t;
