$NetBSD: patch-src_metadata_ffmpeg__handler.cc,v 1.2 2012/11/27 20:16:40 tron Exp $

Fix build with recent versions of "ffmpeg". Partially taken from this
Debian bug report:

http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=677959

--- src/metadata/ffmpeg_handler.cc.orig	2010-03-25 14:58:10.000000000 +0000
+++ src/metadata/ffmpeg_handler.cc	2012-11-27 20:02:25.000000000 +0000
@@ -89,47 +89,30 @@
 
 	Ref<StringConverter> sc = StringConverter::m2i();
     
-	if (strlen(pFormatCtx->title) > 0) 
-    {
-	    log_debug("Added metadata title: %s\n", pFormatCtx->title);
-        item->setMetadata(MT_KEYS[M_TITLE].upnp, 
-                          sc->convert(pFormatCtx->title));
-	}
-	if (strlen(pFormatCtx->author) > 0) 
-    {
-	    log_debug("Added metadata author: %s\n", pFormatCtx->author);
-        item->setMetadata(MT_KEYS[M_ARTIST].upnp, 
-                          sc->convert(pFormatCtx->author));
-	}
-	if (strlen(pFormatCtx->album) > 0) 
-    {
-	    log_debug("Added metadata album: %s\n", pFormatCtx->album);
-        item->setMetadata(MT_KEYS[M_ALBUM].upnp, 
-                          sc->convert(pFormatCtx->album));
-	}
-	if (pFormatCtx->year > 0) 
-    {
-	    log_debug("Added metadata year: %d\n", pFormatCtx->year);
-        item->setMetadata(MT_KEYS[M_DATE].upnp, 
-                          sc->convert(String::from(pFormatCtx->year)));
-	}
-	if (strlen(pFormatCtx->genre) > 0) 
-    {
-	    log_debug("Added metadata genre: %s\n", pFormatCtx->genre);
-        item->setMetadata(MT_KEYS[M_GENRE].upnp, 
-                          sc->convert(pFormatCtx->genre));
-	}
-	if (strlen(pFormatCtx->comment) > 0) 
-    {
-	    log_debug("Added metadata comment: %s\n", pFormatCtx->comment);
-        item->setMetadata(MT_KEYS[M_DESCRIPTION].upnp, 
-                          sc->convert(pFormatCtx->comment));
-	}
-	if (pFormatCtx->track > 0) 
-    {
-	    log_debug("Added metadata track: %d\n", pFormatCtx->track);
-        item->setMetadata(MT_KEYS[M_TRACKNUMBER].upnp, 
-                          sc->convert(String::from(pFormatCtx->track)));
+	typedef struct {const char *avname; metadata_fields_t field;} mapping_t;
+	static const mapping_t mapping[] =
+	{
+		{"title",   M_TITLE},
+		{"artist",  M_ARTIST},
+		{"album",   M_ALBUM},
+		{"date",    M_DATE},
+		{"genre",   M_GENRE},
+		{"comment", M_DESCRIPTION},
+		{"track",   M_TRACKNUMBER},
+		{NULL,      M_MAX},
+	};
+
+	if (!pFormatCtx->metadata)
+		return;
+	for (const mapping_t *m = mapping; m->avname != NULL; m++)
+	{
+		AVDictionaryEntry *tag = NULL;
+		tag = av_dict_get(pFormatCtx->metadata, m->avname, NULL, 0);
+		if (tag && tag->value && tag->value[0])
+		{
+			log_debug("Added metadata %s: %s\n", m->avname, tag->value);
+			item->setMetadata(MT_KEYS[m->field].upnp, sc->convert(tag->value));
+		}
 	}
 }
 
@@ -178,7 +161,7 @@
 	for(i=0; i<pFormatCtx->nb_streams; i++) 
     {
 		AVStream *st = pFormatCtx->streams[i];
-		if((st != NULL) && (videoset == false) && (st->codec->codec_type == CODEC_TYPE_VIDEO))
+		if((st != NULL) && (videoset == false) && (st->codec->codec_type == AVMEDIA_TYPE_VIDEO))
         {
             if (st->codec->codec_tag > 0)
             {
@@ -209,7 +192,7 @@
                 *y = st->codec->height;
 			}
 		} 
-		if(st->codec->codec_type == CODEC_TYPE_AUDIO) 
+		if(st->codec->codec_type == AVMEDIA_TYPE_AUDIO) 
         {
 			// Increase number of audiochannels
 			audioch++;
@@ -251,7 +234,7 @@
     int x = 0;
     int y = 0;
 
-	AVFormatContext *pFormatCtx;
+	AVFormatContext *pFormatCtx = avformat_alloc_context();
 	
 	// Suppress all log messages
 	av_log_set_callback(FfmpegNoOutputStub);
@@ -259,15 +242,15 @@
 	// Register all formats and codecs
     av_register_all();
 
-    // Open video file
-    if (av_open_input_file(&pFormatCtx, 
-                          item->getLocation().c_str(), NULL, 0, NULL) != 0)
+	// Open video file
+    if (avformat_open_input(&pFormatCtx, 
+                          item->getLocation().c_str(), NULL, NULL) != 0)
         return; // Couldn't open file
 
     // Retrieve stream information
-    if (av_find_stream_info(pFormatCtx) < 0)
+    if (avformat_find_stream_info(pFormatCtx,NULL) < 0)
     {
-        av_close_input_file(pFormatCtx);
+        avformat_close_input(&pFormatCtx);
         return; // Couldn't find stream information
     }   
 	// Add metadata using ffmpeg library calls
@@ -276,7 +259,7 @@
 	addFfmpegResourceFields(item, pFormatCtx, &x, &y);
 	
     // Close the video file
-    av_close_input_file(pFormatCtx);
+    avformat_close_input(&pFormatCtx);
 }
 
 Ref<IOHandler> FfmpegHandler::serveContent(Ref<CdsItem> item, int resNum, off_t *data_size)
