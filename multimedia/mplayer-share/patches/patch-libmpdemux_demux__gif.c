$NetBSD: patch-libmpdemux_demux__gif.c,v 1.2 2014/05/16 09:49:06 wiz Exp $

* Fix build with giflib 5.1.

--- libmpdemux/demux_gif.c.orig	2010-12-12 10:37:15.000000000 +0000
+++ libmpdemux/demux_gif.c
@@ -45,6 +45,18 @@ typedef struct {
 
 #define GIF_SIGNATURE (('G' << 16) | ('I' << 8) | 'F')
 
+/* from util/qprintf.c of giflib 5.0.4 */
+void
+PrintGifError(int ErrorCode)
+{
+    char *Err = GifErrorString(ErrorCode);
+
+    if (Err != NULL)
+	fprintf(stderr, "GIF-LIB error: %s.\n", Err);
+    else
+	fprintf(stderr, "GIF-LIB undefined error %d.\n", ErrorCode);
+}
+
 #ifndef CONFIG_GIF_TVT_HACK
 // not supported by certain versions of the library
 static int my_read_gif(GifFileType *gif, uint8_t *buf, int len)
@@ -94,14 +106,14 @@ static int demux_gif_fill_buffer(demuxer
 
   while (type != IMAGE_DESC_RECORD_TYPE) {
     if (DGifGetRecordType(gif, &type) == GIF_ERROR) {
-      PrintGifError();
+      PrintGifError(gif->Error);
       return 0; // oops
     }
     if (type == TERMINATE_RECORD_TYPE)
       return 0; // eof
     if (type == SCREEN_DESC_RECORD_TYPE) {
       if (DGifGetScreenDesc(gif) == GIF_ERROR) {
-        PrintGifError();
+        PrintGifError(gif->Error);
         return 0; // oops
       }
     }
@@ -109,7 +121,7 @@ static int demux_gif_fill_buffer(demuxer
       int code;
       unsigned char *p = NULL;
       if (DGifGetExtension(gif, &code, &p) == GIF_ERROR) {
-        PrintGifError();
+        PrintGifError(gif->Error);
         return 0; // oops
       }
       if (code == 0xF9) {
@@ -138,7 +150,7 @@ static int demux_gif_fill_buffer(demuxer
 	  comments[length] = 0;
 	  printf("%s", comments);
           if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-            PrintGifError();
+            PrintGifError(gif->Error);
             return 0; // oops
           }
 	}
@@ -146,7 +158,7 @@ static int demux_gif_fill_buffer(demuxer
       }
       while (p != NULL) {
         if (DGifGetExtensionNext(gif, &p) == GIF_ERROR) {
-          PrintGifError();
+          PrintGifError(gif->Error);
           return 0; // oops
         }
       }
@@ -154,7 +166,7 @@ static int demux_gif_fill_buffer(demuxer
   }
 
   if (DGifGetImageDesc(gif) == GIF_ERROR) {
-    PrintGifError();
+    PrintGifError(gif->Error);
     return 0; // oops
   }
 
@@ -167,7 +179,7 @@ static int demux_gif_fill_buffer(demuxer
     memset(dp->buffer, gif->SBackGroundColor, priv->w * priv->h);
 
   if (DGifGetLine(gif, buf, len) == GIF_ERROR) {
-    PrintGifError();
+    PrintGifError(gif->Error);
     free(buf);
     return 0; // oops
   }
@@ -257,10 +269,10 @@ static demuxer_t* demux_open_gif(demuxer
   lseek(demuxer->stream->fd, 0, SEEK_SET);
   gif = DGifOpenFileHandle(demuxer->stream->fd);
 #else
-  gif = DGifOpen(demuxer->stream, my_read_gif);
+  gif = DGifOpen(demuxer->stream, my_read_gif, NULL);
 #endif
   if (!gif) {
-    PrintGifError();
+    PrintGifError(gif->Error);
     free(priv);
     return NULL;
   }
@@ -301,8 +313,8 @@ static void demux_close_gif(demuxer_t* d
 {
   gif_priv_t *priv = demuxer->priv;
   if (!priv) return;
-  if (priv->gif && DGifCloseFile(priv->gif) == GIF_ERROR)
-    PrintGifError();
+  if (priv->gif && DGifCloseFile(priv->gif, NULL) == GIF_ERROR)
+    PrintGifError(priv->gif->Error);
   free(priv->refimg);
   free(priv);
 }
