$NetBSD: patch-src_core_download__store.cc,v 1.1 2024/10/04 09:02:01 adam Exp $

Darwin does not define fdatasync(). Fix copied from Qt.
https://github.com/rakshasa/rtorrent/issues/1304

--- src/core/download_store.cc.orig	2024-10-03 17:46:35.720389128 +0000
+++ src/core/download_store.cc
@@ -129,7 +129,11 @@ DownloadStore::write_bencode(const std::
   if (fd < 0)
     goto download_store_save_error;
 
+#if defined(_POSIX_SYNCHRONIZED_IO) && _POSIX_SYNCHRONIZED_IO > 0
   fdatasync(fd);
+#else
+  fsync(fd);
+#endif
   ::close(fd);
 
   return true;
