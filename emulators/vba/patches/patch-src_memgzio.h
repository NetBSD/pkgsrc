$NetBSD: patch-src_memgzio.h,v 1.1 2012/09/29 21:27:14 dholland Exp $

- Use const types correctly: const void * != void *const.

--- src/memgzio.h~	2003-07-24 13:21:52.000000000 +0000
+++ src/memgzio.h
@@ -16,6 +16,6 @@
 
 gzFile ZEXPORT memgzopen(char *memory, int, const char *);
 int ZEXPORT memgzread(gzFile, voidp, unsigned);
-int ZEXPORT memgzwrite(gzFile, const voidp, unsigned);
+int ZEXPORT memgzwrite(gzFile, voidpc, unsigned);
 int ZEXPORT memgzclose(gzFile);
 long ZEXPORT memtell(gzFile);
