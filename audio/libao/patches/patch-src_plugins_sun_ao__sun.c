$NetBSD: patch-src_plugins_sun_ao__sun.c,v 1.1 2019/11/24 00:35:56 nia Exp $

Fix device selection.

--- src/plugins/sun/ao_sun.c.orig	2016-11-14 08:03:30.000000000 +0000
+++ src/plugins/sun/ao_sun.c
@@ -160,7 +160,7 @@ int ao_plugin_open(ao_device *device, ao
 
         if(internal->dev==NULL){
           char buf[80];
-          sprintf(buf,"/dev/sound/%d",internal->id);
+          snprintf(buf,sizeof(buf),"/dev/audio%d",internal->id);
           internal->dev=strdup(buf);
         }
 
