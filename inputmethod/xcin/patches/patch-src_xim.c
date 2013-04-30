$NetBSD: patch-src_xim.c,v 1.1 2013/04/30 22:23:07 joerg Exp $

--- src/xim.c.orig	2013-04-30 11:14:40.000000000 +0000
+++ src/xim.c
@@ -1029,7 +1029,7 @@ xim_init(xccore_t *core)
     XIMTriggerKeys on_keys;
     XIMEncodings encodings;
     Window mainwin;
-    locale_t *locale;
+    xcin_locale_t *locale;
     int i;
 
     transport_type = TRANSPORT_X;
