$NetBSD: patch-src_wutil_dir__iter.rs,v 1.2 2025/11/12 18:44:11 vins Exp $

* Struct dirent lacks d_type on SunOS. 

--- src/wutil/dir_iter.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/wutil/dir_iter.rs
@@ -293,6 +293,8 @@ impl DirIter {
         {
             self.entry.inode = dent.d_ino;
         }
+        #[cfg(not(target_os = "illumos"))]
+        {
         let typ = dirent_type_to_entry_type(dent.d_type);
         // Do not store symlinks as we will need to resolve them.
         if typ != Some(DirEntryType::lnk) {
@@ -300,6 +302,7 @@ impl DirIter {
         }
         // This entry could be a link if it is a link or unknown.
         self.entry.possible_link = typ.map(|t| t == DirEntryType::lnk);
+        }
 
         Some(Ok(&self.entry))
     }
