$NetBSD: patch-src_memgzio.c,v 1.1 2012/09/29 21:27:14 dholland Exp $

- Use const types correctly: const void * != void *const.

--- src/memgzio.c~	2004-01-17 23:07:32.000000000 +0000
+++ src/memgzio.c
@@ -540,7 +540,7 @@ int ZEXPORT memgzread (file, buf, len)
 */
 int ZEXPORT memgzwrite (file, buf, len)
     gzFile file;
-    const voidp buf;
+    voidpc buf;
     unsigned len;
 {
     mem_stream *s = (mem_stream*)file;
