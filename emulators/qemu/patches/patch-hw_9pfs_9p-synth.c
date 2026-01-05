$NetBSD: patch-hw_9pfs_9p-synth.c,v 1.2 2026/01/05 10:11:38 adam Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/9p-synth.c.orig	2025-12-23 19:48:56.000000000 +0000
+++ hw/9pfs/9p-synth.c
@@ -230,7 +230,7 @@ static void synth_direntry(V9fsSynthNode
     entry->d_ino = node->attr->inode;
 #ifdef CONFIG_DARWIN
     entry->d_seekoff = off + 1;
-#else
+#elif defined CONFIG_LINUX
     entry->d_off = off + 1;
 #endif
 }
@@ -447,11 +447,13 @@ static int synth_fsync(FsContext *ctx, i
 static int synth_statfs(FsContext *s, V9fsPath *fs_path,
                              struct statfs *stbuf)
 {
+#ifndef __NetBSD__
     stbuf->f_type = 0xABCD;
+#endif
     stbuf->f_bsize = 512;
     stbuf->f_blocks = 0;
     stbuf->f_files = synth_node_count;
-#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD)
+#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD) && !defined(__NetBSD__)
     stbuf->f_namelen = NAME_MAX;
 #endif
     return 0;
