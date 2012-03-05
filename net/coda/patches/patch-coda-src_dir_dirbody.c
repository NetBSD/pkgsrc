$NetBSD: patch-coda-src_dir_dirbody.c,v 1.1 2012/03/05 11:27:53 gdt Exp $

On NetBSD, force DIRBLKSIZ to 512, which matches the block size (and
thus padding) for the representation of directories in UFS.
coda_readdir will call the readdir from the container filesystem, and
thus the padding of directories must match what the container
filesystem would have done.

Analysis and fix due to Brett Lymn.

Not yet reported upstream; a better fix is desired.

--- coda-src/dir/dirbody.c.orig	2008-10-06 16:52:42.000000000 +0000
+++ coda-src/dir/dirbody.c
@@ -51,6 +51,15 @@ extern "C" {
 #define MMAP_DIR_CONTENTS 1
 #endif
 
+/*
+ * There's a DIRBLKSIZ defined in dirent.h, but the filesystem uses
+ * 512 (DEV_BSIZE).
+ */
+#if defined(__NetBSD__)
+#undef DIRBLKSIZ
+#define DIRBLKSIZ	512
+#endif
+
 #ifndef DIRBLKSIZ
 #define DIRBLKSIZ	0x1000
 #endif
