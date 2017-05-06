$NetBSD: patch-libtiff_tiffio.h,v 1.1.2.2 2017/05/06 15:01:21 bsiegert Exp $

CVE-2017-7593
http://bugzilla.maptools.org/show_bug.cgi?id=2651
https://github.com/vadz/libtiff/commit/d60332057b95

--- libtiff/tiffio.h.orig	2016-01-24 15:39:51.000000000 +0000
+++ libtiff/tiffio.h
@@ -293,6 +293,7 @@ extern TIFFCodec* TIFFGetConfiguredCODEC
  */
 
 extern void* _TIFFmalloc(tmsize_t s);
+extern void* _TIFFcalloc(tmsize_t nmemb, tmsize_t siz);
 extern void* _TIFFrealloc(void* p, tmsize_t s);
 extern void _TIFFmemset(void* p, int v, tmsize_t c);
 extern void _TIFFmemcpy(void* d, const void* s, tmsize_t c);
