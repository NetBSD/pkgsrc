$NetBSD: patch-MagickCore_blob.c,v 1.1 2023/12/30 14:24:29 schmonz Exp $

Apply upstream commit 30274e5 to fix test failures on NetBSD.

--- MagickCore/blob.c.orig	2023-12-10 20:15:36.000000000 +0000
+++ MagickCore/blob.c
@@ -618,8 +618,7 @@ MagickExport MagickBooleanType CloseBlob
   blob_info=image->blob;
   if ((blob_info == (BlobInfo *) NULL) || (blob_info->type == UndefinedStream))
     return(MagickTrue);
-  if (SyncBlob(image) != 0)
-    ThrowBlobException(blob_info);
+  (void) SyncBlob(image);
   status=blob_info->status;
   switch (blob_info->type)
   {
@@ -5518,6 +5517,8 @@ static int SyncBlob(const Image *image)
   assert(image->blob != (BlobInfo *) NULL);
   if (IsEventLogging() != MagickFalse)
     (void) LogMagickEvent(TraceEvent,GetMagickModule(),"%s",image->filename);
+  if (EOFBlob(image) != 0)
+    return(0);
   blob_info=image->blob;
   status=0;
   switch (blob_info->type)
