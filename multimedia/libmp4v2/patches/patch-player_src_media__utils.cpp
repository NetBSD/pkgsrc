$NetBSD: patch-player_src_media__utils.cpp,v 1.1 2017/05/16 09:25:10 jperkin Exp $

C++ strchr() reeturns const char *.

--- player/src/media_utils.cpp.orig	2007-03-29 18:52:19.000000000 +0000
+++ player/src/media_utils.cpp
@@ -610,7 +610,7 @@ static int create_media_for_iptv (CPlaye
   session_desc_t *sdp;
 
   name += strlen("iptv://");
-  slash = strchr(name, '/');
+  slash = (char *)strchr(name, '/');
   if (slash == NULL || slash == name) {
     psptr->set_message("Invalid iptv content manager");
     return -1;
