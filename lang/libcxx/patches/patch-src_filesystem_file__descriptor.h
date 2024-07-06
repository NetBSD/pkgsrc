$NetBSD: patch-src_filesystem_file__descriptor.h,v 1.2 2024/07/06 15:45:07 adam Exp $

Support POSIX file modes.

--- src/filesystem/file_descriptor.h.orig	2024-04-17 00:21:15.000000000 +0000
+++ src/filesystem/file_descriptor.h
@@ -41,7 +41,21 @@ namespace detail {
 #  if defined(DT_BLK)
 template <class DirEntT, class = decltype(DirEntT::d_type)>
 file_type get_file_type(DirEntT* ent, int) {
+#ifdef __sun
+#define DT_BLK		S_IFBLK
+#define DT_CHR		S_IFCHR
+#define DT_DIR		S_IFDIR
+#define DT_FIFO		S_IFIFO
+#define DT_LNK		S_IFLNK
+#define DT_REG		S_IFREG
+#define DT_SOCK		S_IFSOCK
+#define DT_UNKNOWN	0
+  struct stat s;
+  stat(ent->d_name, &s);
+  switch (s.st_mode & 0xF000) {
+#else
   switch (ent->d_type) {
+#endif
   case DT_BLK:
     return file_type::block;
   case DT_CHR:
