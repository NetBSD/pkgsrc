$NetBSD: patch-src_wutil_dir__iter.rs,v 1.2 2025/12/31 00:47:59 ktnb Exp $

Struct dirent lacks d_type on SunOS.

--- src/wutil/dir_iter.rs.orig	2025-12-28 15:54:44.000000000 +0000
+++ src/wutil/dir_iter.rs
@@ -292,6 +292,8 @@ impl DirIter {
                 self.entry.inode = dent.d_ino;
             }
         );
+        #[cfg(not(target_os = "illumos"))]
+        {
         let typ = dirent_type_to_entry_type(dent.d_type);
         // Do not store symlinks as we will need to resolve them.
         if typ != Some(DirEntryType::Lnk) {
@@ -299,7 +301,7 @@ impl DirIter {
         }
         // This entry could be a link if it is a link or unknown.
         self.entry.possible_link = typ.map(|t| t == DirEntryType::Lnk);
-
+        }
         Some(Ok(&self.entry))
     }
 }
