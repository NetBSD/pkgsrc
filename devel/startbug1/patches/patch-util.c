$NetBSD: patch-util.c,v 1.1 2014/01/08 14:59:15 ryoon Exp $

* Fix build

--- util.c.orig	2012-11-28 06:40:22.000000000 +0000
+++ util.c
@@ -836,7 +836,7 @@ void set_locale(char* locale)
         putenv(envstr);
     }
 #endif
-    setlocale(LC_ALL, locale_utf8);
+    setlocale("LC_ALL", locale_utf8);
     bindtextdomain("starbug1", locale_dir);
     textdomain("starbug1");
 #ifdef _WIN32
