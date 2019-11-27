$NetBSD: patch-Source_cmArchiveWrite.cxx,v 1.2 2019/11/27 22:32:27 adam Exp $

Allow older libarchive without ZSTD support.

--- Source/cmArchiveWrite.cxx.orig	2019-11-26 14:18:07.000000000 +0000
+++ Source/cmArchiveWrite.cxx
@@ -141,6 +141,7 @@ cmArchiveWrite::cmArchiveWrite(std::ostr
         return;
       }
       break;
+#ifdef ARCHIVE_FILTER_ZSTD
     case CompressZstd:
       if (archive_write_add_filter_zstd(this->Archive) != ARCHIVE_OK) {
         this->Error = cmStrCat("archive_write_add_filter_zstd: ",
@@ -148,6 +149,7 @@ cmArchiveWrite::cmArchiveWrite(std::ostr
         return;
       }
       break;
+#endif
   }
 #if !defined(_WIN32) || defined(__CYGWIN__)
   if (archive_read_disk_set_standard_lookup(this->Disk) != ARCHIVE_OK) {
