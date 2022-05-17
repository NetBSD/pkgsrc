$NetBSD: patch-stream_stream__libarchive.c,v 1.1 2022/05/17 13:12:13 ryoon Exp $

* NetBSD does not implement uselocale().

--- stream/stream_libarchive.c.orig	2022-01-03 19:45:08.000000000 +0000
+++ stream/stream_libarchive.c
@@ -29,6 +29,10 @@
 #define MP_ARCHIVE_FLAG_MAYBE_RAR       (MP_ARCHIVE_FLAG_PRIV << 1)
 #define MP_ARCHIVE_FLAG_MAYBE_VOLUMES   (MP_ARCHIVE_FLAG_PRIV << 2)
 
+#if defined(__NetBSD__)
+#define uselocale(locale) NULL
+#endif
+
 struct mp_archive_volume {
     struct mp_archive *mpa;
     int index; // volume number (starting with 0, mp_archive.primary_src)
