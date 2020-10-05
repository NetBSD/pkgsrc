$NetBSD: patch-MagickCore_cache.c,v 1.1 2020/10/05 17:23:29 triaxx Exp $

Fix build on FreeBSD
https://github.com/triaxx/ImageMagick/commit/11583e4

--- MagickCore/cache.c.orig	2020-10-04 15:44:21.000000000 +0000
+++ MagickCore/cache.c
@@ -621,7 +621,7 @@ static MagickBooleanType ClonePixelCacheOnDisk(
   quantum=(size_t) MagickMaxBufferExtent;
   if ((fstat(cache_info->file,&file_stats) == 0) && (file_stats.st_size > 0))
     {
-#if defined(MAGICKCORE_HAVE_SENDFILE) && !defined(__APPLE__)
+#if defined(MAGICKCORE_HAVE_SENDFILE) && !defined(__APPLE__) && !defined(__FreeBSD__)
       if (cache_info->length < 0x7ffff000)
         {
           count=sendfile(clone_info->file,cache_info->file,(off_t *) NULL,
