$NetBSD: patch-hw_9pfs_9p-synth.c,v 1.1 2025/03/15 20:19:15 riastradh Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/9p-synth.c.orig	2024-12-10 23:46:36.000000000 +0000
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
@@ -433,11 +433,13 @@ static int synth_fsync(FsContext *ctx, i
 static int synth_statfs(FsContext *s, V9fsPath *fs_path,
                              struct statfs *stbuf)
 {
+#ifndef __NetBSD__
     stbuf->f_type = 0xABCD;
+#endif
     stbuf->f_bsize = 512;
     stbuf->f_blocks = 0;
     stbuf->f_files = synth_node_count;
-#ifndef CONFIG_DARWIN
+#ifdef CONFIG_LINUX
     stbuf->f_namelen = NAME_MAX;
 #endif
     return 0;
