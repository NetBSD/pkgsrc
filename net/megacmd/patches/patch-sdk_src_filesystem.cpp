$NetBSD: patch-sdk_src_filesystem.cpp,v 1.1 2025/05/16 19:43:58 wiz Exp $

* Add BSD supported filesystems

--- sdk/src/filesystem.cpp.orig	2025-04-17 16:07:37.374980956 +0200
+++ sdk/src/filesystem.cpp
@@ -785,8 +785,12 @@ const char *FileSystemAccess::fstypetost
             return "EXFAT";
         case FS_FAT32:
             return "FAT32";
+        case FS_FFS:
+            return "FFS";
         case FS_EXT:
             return "EXT";
+        case FS_HAMMER :
+            return "HAMMER";
         case FS_HFS:
             return "HFS";
         case FS_APFS:
@@ -809,6 +813,10 @@ const char *FileSystemAccess::fstypetost
             return "SMB2";
         case FS_LIFS:
             return "LIFS";
+        case FS_UFS:
+            return "UFS";
+        case FS_ZFS:
+            return "ZFS";
         case FS_UNKNOWN:    // fall through
             return "UNKNOWN FS";
     }
@@ -884,7 +892,11 @@ bool FileSystemAccess::islocalfscompatib
     case FS_APFS:
     case FS_EXT:
     case FS_F2FS:
+    case FS_FFS:
+    case FS_HAMMER:
+    case FS_UFS:
     case FS_XFS:
+    case FS_ZFS:
         return character != '/';
     case FS_EXFAT:
     case FS_FAT32:
