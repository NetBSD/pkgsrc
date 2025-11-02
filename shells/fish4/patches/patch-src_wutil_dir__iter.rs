$NetBSD: patch-src_wutil_dir__iter.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

* Struct dirent lacks d_type on SunOS. 
* Prevent type clash on illumos. 

--- src/wutil/dir_iter.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/wutil/dir_iter.rs
@@ -21,7 +21,7 @@ pub enum DirEntryType {
     chr,      // character device
     dir,      // directory
     blk,      // block device
-    reg,      // regular file
+    regr,      // regular file
     lnk,      // symlink
     sock,     // socket
     whiteout, // whiteout (from BSD)
@@ -142,7 +142,7 @@ fn dirent_type_to_entry_type(dt: u8) ->
         DT_CHR => Some(DirEntryType::chr),
         DT_DIR => Some(DirEntryType::dir),
         DT_BLK => Some(DirEntryType::blk),
-        DT_REG => Some(DirEntryType::reg),
+        DT_REG => Some(DirEntryType::regr),
         DT_LNK => Some(DirEntryType::lnk),
         DT_SOCK => Some(DirEntryType::sock),
         // todo!("whiteout")
@@ -156,7 +156,7 @@ fn stat_mode_to_entry_type(m: libc::mode
         S_IFCHR => Some(DirEntryType::chr),
         S_IFDIR => Some(DirEntryType::dir),
         S_IFBLK => Some(DirEntryType::blk),
-        S_IFREG => Some(DirEntryType::reg),
+        S_IFREG => Some(DirEntryType::regr),
         S_IFLNK => Some(DirEntryType::lnk),
         S_IFSOCK => Some(DirEntryType::sock),
         _ => {
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
@@ -448,9 +451,9 @@ fn test_dir_iter() {
         let expected = if entry.name == dirname {
             Some(DirEntryType::dir)
         } else if entry.name == regname {
-            Some(DirEntryType::reg)
+            Some(DirEntryType::regr)
         } else if entry.name == reglinkname {
-            Some(DirEntryType::reg)
+            Some(DirEntryType::regr)
         } else if entry.name == dirlinkname {
             Some(DirEntryType::dir)
         } else if entry.name == badlinkname {
