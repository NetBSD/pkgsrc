$NetBSD: patch-fontforge_splinefont.h,v 1.2 2016/09/27 10:24:57 taca Exp $

* NetBSD does not implement uselocale().
* NetBSD prior to 7.0 dose not have locale_t.

--- fontforge/splinefont.h.orig	2016-04-05 01:29:03.000000000 +0000
+++ fontforge/splinefont.h
@@ -3549,6 +3549,20 @@ char * delimit_null(const char * input, 
 
 #include "ustring.h"
 
+#ifdef __NetBSD__
+#define BAD_LOCALE_HACK
+#ifndef __LOCALE_T_DECLARED
+typedef char* locale_t;
+#define LC_GLOBAL_LOCALE ((locale_t)-1)
+#define LC_ALL_MASK LC_ALL
+#define LC_COLLATE_MASK LC_COLLATE
+#define LC_CTYPE_MASK LC_CTYPE
+#define LC_MONETARY_MASK LC_MONETARY
+#define LC_NUMERIC_MASK LC_NUMERIC
+#define LC_TIME_MASK LC_TIME
+#endif
+#endif
+
 #ifdef _WIN32
 #define BAD_LOCALE_HACK
 typedef char* locale_t;
