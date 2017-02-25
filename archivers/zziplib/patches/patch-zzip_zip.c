$NetBSD: patch-zzip_zip.c,v 1.1 2017/02/25 12:16:44 kamil Exp $

Fix inline function error reference:
work/zziplib-0.13.59/zzip/.libs/libzzip.so: undefined reference to `__zzip_aligned4'

Replace _zzip_inline with regular static inline.

--- zzip/zip.c.orig	2009-09-24 21:57:00.000000000 +0000
+++ zzip/zip.c
@@ -90,7 +90,7 @@ int __zzip_parse_root_directory(int fd,
                                 struct zzip_dir_hdr **hdr_return,
                                 zzip_plugin_io_t io);
 
-_zzip_inline char *__zzip_aligned4(char *p);
+static inline char *__zzip_aligned4(char *p);
 
 /* ------------------------  harden routines ------------------------------ */
 
@@ -377,7 +377,7 @@ __zzip_fetch_disk_trailer(int fd, zzip_o
  * to pointer types but we do need only the lower bits in this implementation,
  * so we can just cast the value to a long value.
  */
-_zzip_inline char *
+static inline char *
 __zzip_aligned4(char *p)
 {
 #define aligned4   __zzip_aligned4
