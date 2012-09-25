$NetBSD: patch-src_metadata_ffmpeg__handler.cc,v 1.1 2012/09/25 11:45:11 ryoon Exp $

--- src/metadata/ffmpeg_handler.cc.orig	2010-03-25 14:58:10.000000000 +0000
+++ src/metadata/ffmpeg_handler.cc
@@ -89,47 +89,30 @@ static void addFfmpegMetadataFields(Ref<
 
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
+		AVMetadataTag *tag = NULL;
+		tag = av_metadata_get(pFormatCtx->metadata, m->avname, NULL, 0);
+		if (tag && tag->value && tag->value[0])
+		{
+			log_debug("Added metadata %s: %s\n", m->avname, tag->value);
+			item->setMetadata(MT_KEYS[m->field].upnp, sc->convert(tag->value));
+		}
 	}
 }
 
@@ -178,7 +161,7 @@ static void addFfmpegResourceFields(Ref<
 	for(i=0; i<pFormatCtx->nb_streams; i++) 
     {
 		AVStream *st = pFormatCtx->streams[i];
-		if((st != NULL) && (videoset == false) && (st->codec->codec_type == CODEC_TYPE_VIDEO))
+		if((st != NULL) && (videoset == false) && (st->codec->codec_type == AVMEDIA_TYPE_VIDEO))
         {
             if (st->codec->codec_tag > 0)
             {
@@ -209,7 +192,7 @@ static void addFfmpegResourceFields(Ref<
                 *y = st->codec->height;
 			}
 		} 
-		if(st->codec->codec_type == CODEC_TYPE_AUDIO) 
+		if(st->codec->codec_type == AVMEDIA_TYPE_AUDIO) 
         {
 			// Increase number of audiochannels
 			audioch++;
