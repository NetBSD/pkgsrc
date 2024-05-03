$NetBSD: patch-libs_indicore_sharedblob.c,v 1.1 2024/05/03 11:17:14 wiz Exp $

Check for symbol existence before using it.

--- libs/indicore/sharedblob.c.orig	2024-05-03 10:31:58.021138213 +0000
+++ libs/indicore/sharedblob.c
@@ -225,7 +225,7 @@ void * IDSharedBlobRealloc(void * ptr, s
     int ret = ftruncate(sb->fd, reallocated);
     if (ret == -1) return NULL;
 
-#ifdef HAVE_MREMAP
+#ifdef MREMAP_MAYMOVE
     void * remaped = mremap(sb->mapstart, sb->allocated, reallocated, MREMAP_MAYMOVE);
     if (remaped == MAP_FAILED) return NULL;
 
