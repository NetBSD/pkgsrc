$NetBSD: patch-libtiff_tif_unix.c,v 1.1.2.2 2017/05/06 15:01:21 bsiegert Exp $

CVE-2017-7593
http://bugzilla.maptools.org/show_bug.cgi?id=2651
https://github.com/vadz/libtiff/commit/d60332057b95

--- libtiff/tif_unix.c.orig	2015-08-28 22:16:22.000000000 +0000
+++ libtiff/tif_unix.c
@@ -316,6 +316,14 @@ _TIFFmalloc(tmsize_t s)
 	return (malloc((size_t) s));
 }
 
+void* _TIFFcalloc(tmsize_t nmemb, tmsize_t siz)
+{
+    if( nmemb == 0 || siz == 0 )
+        return ((void *) NULL);
+
+    return calloc((size_t) nmemb, (size_t)siz);
+}
+
 void
 _TIFFfree(void* p)
 {
