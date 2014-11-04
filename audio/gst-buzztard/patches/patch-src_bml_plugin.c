$NetBSD: patch-src_bml_plugin.c,v 1.1 2014/11/04 21:38:15 joerg Exp $

--- src/bml/plugin.c.orig	2014-11-04 12:02:37.000000000 +0000
+++ src/bml/plugin.c
@@ -400,7 +400,7 @@ static gboolean plugin_init (GstPlugin *
 #endif
 
   // init bml library
-  if(!bml_setup(0)) {
+  if(!bml_setup()) {
     GST_WARNING("failed to init bml library");
     return(FALSE);
   }
