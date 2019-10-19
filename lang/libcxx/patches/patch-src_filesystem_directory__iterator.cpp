$NetBSD: patch-src_filesystem_directory__iterator.cpp,v 1.2 2019/10/19 13:59:07 adam Exp $

Support POSIX file modes.

--- src/filesystem/directory_iterator.cpp.orig	2019-02-01 23:52:17.000000000 +0000
+++ src/filesystem/directory_iterator.cpp
@@ -28,7 +28,21 @@ namespace {
 #if defined(DT_BLK)
 template <class DirEntT, class = decltype(DirEntT::d_type)>
 static file_type get_file_type(DirEntT* ent, int) {
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
