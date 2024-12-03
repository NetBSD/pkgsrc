$NetBSD: patch-src_in_flac.c,v 1.1 2024/12/03 09:57:13 kim Exp $

Adapt to latest libFLAC API.

--- src/in_flac.c.orig	2004-07-31 17:52:24.000000000 +0000
+++ src/in_flac.c
@@ -76,18 +76,10 @@ ices_flac_open (input_stream_t* self, ch
     return -1;
   }
 
-  FLAC__stream_decoder_set_read_callback(decoder, flac_read_cb);
-  FLAC__stream_decoder_set_write_callback(decoder, flac_write_cb);
-  FLAC__stream_decoder_set_metadata_callback(decoder, flac_metadata_cb);
-  FLAC__stream_decoder_set_error_callback(decoder, flac_error_cb);
-
-  FLAC__stream_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_VORBIS_COMMENT);
-
   if (!(flac_data = (flac_in_t*)malloc (sizeof (flac_in_t)))) {
     ices_log_error ("Malloc failed in ices_flac_open");
     goto errDecoder;
   }
-  FLAC__stream_decoder_set_client_data(decoder, self);
 
   flac_data->decoder = decoder;
   flac_data->parsed = 0;
@@ -96,8 +88,13 @@ ices_flac_open (input_stream_t* self, ch
 
   self->data = flac_data;
 
-  switch (FLAC__stream_decoder_init(decoder)) {
-  case FLAC__STREAM_DECODER_SEARCH_FOR_METADATA:
+  /* This needs to be called before initializing the decoder. */
+  FLAC__stream_decoder_set_metadata_respond(decoder, FLAC__METADATA_TYPE_VORBIS_COMMENT);
+
+  switch (FLAC__stream_decoder_init_stream(decoder,
+      flac_read_cb, NULL, NULL, NULL, NULL, /* seek, tell, length, eof */
+      flac_write_cb, flac_metadata_cb, flac_error_cb, self)) {
+  case FLAC__STREAM_DECODER_INIT_STATUS_OK:
     break;
   case FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR:
     ices_log_error("Could not allocate memory during FLAC decoder init");
@@ -193,8 +190,10 @@ flac_read_cb(const FLAC__StreamDecoder* 
     }
     if ((len = read(self->fd, buffer, *bytes)) > 0)
       return FLAC__STREAM_DECODER_READ_STATUS_CONTINUE;
-    if (!len)
+    if (!len) {
+      *bytes = 0;
       return FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM;
+    }
     ices_log_error("Error reading FLAC stream: %s", ices_util_strerror(errno, errbuf, sizeof(errbuf)));
     return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
   }
@@ -251,10 +250,10 @@ flac_metadata_cb(const FLAC__StreamDecod
     for (i = 0; i < metadata->data.vorbis_comment.num_comments; i++) {
       comment = metadata->data.vorbis_comment.comments + i;
 
-      if (comment->length >= 6 && !strncasecmp("artist", comment->entry, 6)) {
+      if (comment->length >= 7 && !strncasecmp("artist=", comment->entry, 7)) {
 	if ((artist = malloc(comment->length - 6)))
 	  snprintf(artist, comment->length - 6, "%s", comment->entry + 7);
-      } else if (comment->length >= 5 && !strncasecmp("title", comment->entry, 5)) {
+      } else if (comment->length >= 6 && !strncasecmp("title=", comment->entry, 6)) {
 	if ((title = malloc(comment->length - 5)))
 	  snprintf(title, comment->length - 5, "%s", comment->entry + 6);
       }
