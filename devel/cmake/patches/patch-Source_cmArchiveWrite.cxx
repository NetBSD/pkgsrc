$NetBSD: patch-Source_cmArchiveWrite.cxx,v 1.1 2019/07/19 09:06:23 adam Exp $

Allow older libarchive without ZSTD support.

--- Source/cmArchiveWrite.cxx.orig	2019-07-19 08:41:01.000000000 +0000
+++ Source/cmArchiveWrite.cxx
@@ -137,6 +137,7 @@ cmArchiveWrite::cmArchiveWrite(std::ostr
         return;
       }
       break;
+#ifdef ARCHIVE_FILTER_ZSTD
     case CompressZstd:
       if (archive_write_add_filter_zstd(this->Archive) != ARCHIVE_OK) {
         this->Error = "archive_write_add_filter_zstd: ";
@@ -144,6 +145,7 @@ cmArchiveWrite::cmArchiveWrite(std::ostr
         return;
       }
       break;
+#endif
   }
 #if !defined(_WIN32) || defined(__CYGWIN__)
   if (archive_read_disk_set_standard_lookup(this->Disk) != ARCHIVE_OK) {
