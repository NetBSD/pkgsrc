$NetBSD: patch-src_filesystem_directory__iterator.cpp,v 1.1 2018/12/17 16:07:09 jperkin Exp $

Support POSIX file modes.

--- src/filesystem/directory_iterator.cpp.orig	2018-07-27 03:07:09.000000000 +0000
+++ src/filesystem/directory_iterator.cpp
@@ -27,7 +27,21 @@ namespace {
 #if !defined(_LIBCPP_WIN32API)
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
