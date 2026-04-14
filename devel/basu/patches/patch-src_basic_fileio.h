$NetBSD: patch-src_basic_fileio.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* NetBSD hasn't ferror_unlocked()

--- src/basic/fileio.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/fileio.h
@@ -3,6 +3,9 @@
 
 #include <stddef.h>
 #include <stdio.h>
+#ifdef __NetBSD__
+#define ferror_unlocked(fp) ferror(fp)
+#endif
 
 int read_one_line_file(const char *fn, char **line);
 int read_full_file(const char *fn, char **contents, size_t *size);
