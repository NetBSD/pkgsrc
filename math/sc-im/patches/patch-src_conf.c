$NetBSD: patch-src_conf.c,v 1.1 2019/12/25 17:34:11 sjmulder Exp $

Fix build on Solaris-likes which don't have tm_gmtoff.

--- src/conf.c.orig	2017-12-13 17:48:59.000000000 +0000
+++ src/conf.c
@@ -98,8 +98,8 @@ void store_default_config_values() {
     put(user_conf_d, "default_paste_from_clipboard_cmd", "");
     #endif
 
-    // we calc get gmtoffset
-    #ifdef USELOCALE
+    // Calculate GMT offset (not on Solaris, doesn't have tm_gmtoff)
+    #if defined(USELOCALE) && !defined(__sun)
     time_t t = time(NULL);
     struct tm * lt = localtime(&t);
     char strgmtoff[7];
