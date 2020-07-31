$NetBSD: patch-Source_cmArchiveWrite.cxx,v 1.4 2020/07/31 09:42:10 adam Exp $

Libarchive from PkgSrc currenty does not support ZSTD.

--- Source/cmArchiveWrite.cxx.orig	2020-07-20 09:34:34.000000000 +0000
+++ Source/cmArchiveWrite.cxx
@@ -143,13 +143,6 @@ cmArchiveWrite::cmArchiveWrite(std::ostr
         return;
       }
       break;
-    case CompressZstd:
-      if (archive_write_add_filter_zstd(this->Archive) != ARCHIVE_OK) {
-        this->Error = cmStrCat("archive_write_add_filter_zstd: ",
-                               cm_archive_error_string(this->Archive));
-        return;
-      }
-      break;
   }
 #if !defined(_WIN32) || defined(__CYGWIN__)
   if (archive_read_disk_set_standard_lookup(this->Disk) != ARCHIVE_OK) {
