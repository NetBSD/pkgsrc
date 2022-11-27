$NetBSD: patch-src_plugins_PamAuth_pamauth.c,v 1.1 2022/11/27 13:14:00 triaxx Exp $

Suppress warning for incompatibility with strdup() return type.

--- src/plugins/PamAuth/pamauth.c.orig	2021-07-01 16:59:57.000000000 +0000
+++ src/plugins/PamAuth/pamauth.c
@@ -132,7 +132,7 @@ PLUGINAPI int PLUGINCALL start(struct pl
  if(argc < 2) return 1;
  pl = pluginlink;
  if(service) free(service);
- service=strdup((char *)argv[1]); 
+ service = (unsigned char *)strdup((char *)argv[1]); 
 
  if (already_loaded) { return (0); }
 
