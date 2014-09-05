$NetBSD: patch-src_libs3decoder_libsearch_vithist.c,v 1.1 2014/09/05 10:13:21 fhajny Exp $

Fix heap declaration.
--- src/libs3decoder/libsearch/vithist.c.orig	2008-12-31 18:27:56.000000000 +0000
+++ src/libs3decoder/libsearch/vithist.c
@@ -647,7 +647,7 @@ vithist_prune(vithist_t * vh, dict_t * d
 {
     int32 se, fe, filler_done, th;
     vithist_entry_t *ve;
-    heap_t h;
+    heap_t* h;
     s3wid_t *wid;
     int32 i;
 
