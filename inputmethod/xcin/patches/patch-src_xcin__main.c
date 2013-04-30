$NetBSD: patch-src_xcin__main.c,v 1.1 2013/04/30 22:23:07 joerg Exp $

--- src/xcin_main.c.orig	2013-04-30 11:14:44.000000000 +0000
+++ src/xcin_main.c
@@ -56,7 +56,7 @@ void xim_init(xccore_t *xccore);
 static void
 xcin_setlocale(void)
 {
-    locale_t *locale = &(xcin_core.xcin_rc.locale);
+    xcin_locale_t *locale = &(xcin_core.xcin_rc.locale);
     char loc_return[128], enc_return[128];
 
     set_perr("xcin");
@@ -324,7 +324,7 @@ read_core_config_locale(void)
     char *cmd[2], value[256], *s, loc_buf[64], *loc_name=NULL;
     char *fmt = N_("%s:\n\tlocale section \"%s\": %s: value not specified.\n");
     xcin_rc_t *xrc = &(xcin_core.xcin_rc);
-    locale_t *locale = &(xcin_core.xcin_rc.locale);
+    xcin_locale_t *locale = &(xcin_core.xcin_rc.locale);
 /*
  *  Determine the true locale setting name.
  */
@@ -401,7 +401,7 @@ read_core_config_IM(void)
     char *cmd[2], value[256], *s, *s1, objname[100], objenc[100];
     char *fmt = N_("%s:\n\tIM section \"%s\": %s: value not specified.\n");
     xcin_rc_t *xrc = &(xcin_core.xcin_rc);
-    locale_t *locale = &(xcin_core.xcin_rc.locale);
+    xcin_locale_t *locale = &(xcin_core.xcin_rc.locale);
     int setkey;
 /*
  *  Go to each CINPUT sub-node and read important keywords.
