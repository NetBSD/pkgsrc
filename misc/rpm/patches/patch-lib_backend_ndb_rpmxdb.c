$NetBSD: patch-lib_backend_ndb_rpmxdb.c,v 1.1 2025/02/07 15:06:19 adam Exp $

Fix build.

--- lib/backend/ndb/rpmxdb.c.orig	2025-02-07 14:43:10.414632541 +0000
+++ lib/backend/ndb/rpmxdb.c
@@ -107,7 +107,7 @@ static inline void h2lea(unsigned int x,
 static void *mapmem(void *oldaddr, size_t oldsize, size_t newsize, int prot, int fd, off_t offset)
 {
     if (oldaddr) {
-#ifdef HAVE_MREMAP
+#if defined(HAVE_MREMAP) && defined(MREMAP_MAYMOVE)
 	return mremap(oldaddr, oldsize, newsize, MREMAP_MAYMOVE);
 #else
 	void *mapped = mmap(0, newsize, prot, MAP_SHARED, fd, offset);
