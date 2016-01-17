$NetBSD: patch-src_media-stream.c,v 1.1 2016/01/17 18:51:52 wiz Exp $

Adapt to libpurple changes.

--- src/media-stream.c.orig	2013-09-23 16:51:19.000000000 +0000
+++ src/media-stream.c
@@ -1076,7 +1076,7 @@ haze_media_stream_new_native_candidate (
       if (proto == TP_MEDIA_STREAM_BASE_PROTO_UDP)
         protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_UDP;
       else if (proto == TP_MEDIA_STREAM_BASE_PROTO_TCP)
-        protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_TCP;
+        protocol = PURPLE_MEDIA_NETWORK_PROTOCOL_TCP_ACTIVE;
       else
         DEBUG ("Unknown network protocol");
 
