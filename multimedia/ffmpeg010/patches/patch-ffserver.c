$NetBSD: patch-ffserver.c,v 1.1 2012/12/19 12:53:25 joerg Exp $

--- ffserver.c.orig	2012-12-19 10:57:22.000000000 +0000
+++ ffserver.c
@@ -3806,7 +3806,7 @@ static void add_codec(FFStream *stream, 
     AVStream *st;
 
     if(stream->nb_streams >= FF_ARRAY_ELEMS(stream->streams))
-        return NULL;
+        return;
 
     /* compute default parameters */
     switch(av->codec_type) {
