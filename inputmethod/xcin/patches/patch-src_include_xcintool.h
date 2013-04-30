$NetBSD: patch-src_include_xcintool.h,v 1.1 2013/04/30 22:23:07 joerg Exp $

--- src/include/xcintool.h.orig	2013-04-30 11:13:51.000000000 +0000
+++ src/include/xcintool.h
@@ -202,12 +202,12 @@ typedef struct {
     char *lc_messages;
     char *encoding;
     int encid, locid;
-} locale_t;
+} xcin_locale_t;
 
 typedef struct {
     int argc;			/* Command line arguement list */
     char **argv;
-    locale_t locale;            /* Locale name. */
+    xcin_locale_t locale;            /* Locale name. */
     char *usrhome;		/* User home directory. */
     char *default_dir;          /* Default module directory. */
     char *user_dir;             /* User data directory. */
