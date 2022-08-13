$NetBSD: patch-src_filesystem_filesystem__common.h,v 1.1 2022/08/13 09:38:09 tnn Exp $

Support POSIX file modes.

--- src/filesystem/filesystem_common.h.orig	2022-06-22 16:46:24.000000000 +0000
+++ src/filesystem/filesystem_common.h
@@ -538,7 +538,21 @@ bool set_file_times(const path& p, std::
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
