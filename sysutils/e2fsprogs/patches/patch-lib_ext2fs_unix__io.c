$NetBSD: patch-lib_ext2fs_unix__io.c,v 1.1 2024/08/03 07:33:29 wiz Exp $

Handle character devices on NetBSD like on FreeBSD.
PR 58545 by RVP.

--- lib/ext2fs/unix_io.c.orig	2021-08-19 02:53:01.000000000 +0000
+++ lib/ext2fs/unix_io.c
@@ -758,7 +758,7 @@ static errcode_t unix_open_channel(const
 		io->align = 512;
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 	if (io->flags & CHANNEL_FLAGS_BLOCK_DEVICE) {
 		int dio_align = ext2fs_get_dio_alignment(fd);
 
