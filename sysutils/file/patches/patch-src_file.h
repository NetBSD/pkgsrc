$NetBSD: patch-src_file.h,v 1.1 2014/11/07 11:17:12 schmonz Exp $

Some OSes have locale_t in xlocale.h (patch from upstream).

--- src/file.h.orig	2014-09-11 15:05:33.000000000 +0000
+++ src/file.h
@@ -474,6 +474,9 @@ protected int file_os2_apptype(struct ma
 #if defined(HAVE_LOCALE_H)
 #include <locale.h>
 #endif
+#if defined(HAVE_XLOCALE_H)
+#include <xlocale.h>
+#endif
 
 typedef struct {
 	const char *pat;
