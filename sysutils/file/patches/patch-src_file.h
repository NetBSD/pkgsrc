$NetBSD: patch-src_file.h,v 1.3 2019/03/16 09:02:41 bsiegert Exp $

fix PR/62: spinpx: limit size of file_printable.  (CVE-2019-8904)

https://bugs.astron.com/view.php?id=62
https://github.com/file/file/commit/d65781527c8134a1202b2649695d48d5701ac60b

--- src/file.h.orig	2017-08-28 13:39:18.000000000 +0000
+++ src/file.h
@@ -491,7 +491,7 @@ protected int file_looks_utf8(const unsi
     size_t *);
 protected size_t file_pstring_length_size(const struct magic *);
 protected size_t file_pstring_get_length(const struct magic *, const char *);
-protected char * file_printable(char *, size_t, const char *);
+protected char * file_printable(char *, size_t, const char *, size_t);
 #ifdef __EMX__
 protected int file_os2_apptype(struct magic_set *, const char *, const void *,
     size_t);
