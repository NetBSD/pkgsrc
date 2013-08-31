$NetBSD: patch-src_tags_gnome-cmd-tags-poppler.cc,v 1.2 2013/08/31 14:54:47 joerg Exp $

Fix build with recent poppler.

--- src/tags/gnome-cmd-tags-poppler.cc.orig	2011-12-06 19:10:29.000000000 +0000
+++ src/tags/gnome-cmd-tags-poppler.cc
@@ -41,7 +41,7 @@ using namespace std;
 static regex_t rxDate;
 static gboolean rxDate_OK;
 
-static void noErrorReporting(int pos, char *msg, va_list args)
+static void noErrorReporting(void *, ErrorCategory, Goffset pos, char *msg)
 {
 }
 #endif
@@ -52,7 +52,7 @@ void gcmd_tags_poppler_init()
 #ifdef HAVE_PDF
     rxDate_OK = regcomp (&rxDate, "^(D:)?([12][019][0-9][0-9]([01][0-9]([0-3][0-9]([012][0-9]([0-5][0-9]([0-5][0-9])?)?)?)?)?)", REG_EXTENDED)==0;
 
-    setErrorFunction(noErrorReporting);
+    setErrorCallback(noErrorReporting, NULL);
 #endif
 }
 
