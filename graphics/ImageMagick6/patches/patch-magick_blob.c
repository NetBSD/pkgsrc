$NetBSD: patch-magick_blob.c,v 1.1 2023/12/31 20:40:32 gutteridge Exp $

Fix regression that was causing image generation failures on NetBSD.
https://github.com/ImageMagick/ImageMagick/issues/6984
https://github.com/ImageMagick/ImageMagick6/commit/a1e5ff811aeb935f7adfa4740026c59dac2bb01f

--- magick/blob.c.orig	2023-12-25 14:08:06.000000000 +0000
+++ magick/blob.c
@@ -522,8 +522,7 @@ MagickExport MagickBooleanType CloseBlob
   blob_info=image->blob;
   if ((blob_info == (BlobInfo *) NULL) || (blob_info->type == UndefinedStream))
     return(MagickTrue);
-  if (SyncBlob(image) != 0)
-    ThrowBlobException(blob_info);
+  (void) SyncBlob(image);
   status=blob_info->status;
   switch (blob_info->type)
   {
@@ -4735,6 +4734,8 @@ static int SyncBlob(const Image *image)
   assert(image->blob != (BlobInfo *) NULL);
   if (IsEventLogging() != MagickFalse)
     (void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",image->filename);
+  if (EOFBlob(image) != 0)
+    return(0);
   blob_info=image->blob;
   status=0;
   switch (blob_info->type)
