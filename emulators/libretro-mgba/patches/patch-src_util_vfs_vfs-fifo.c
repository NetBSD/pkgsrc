$NetBSD: patch-src_util_vfs_vfs-fifo.c,v 1.1 2018/09/07 18:54:02 nia Exp $

vfs.sync's buffer pointer isn't const.

--- src/util/vfs/vfs-fifo.c.orig	2018-04-14 20:49:19.000000000 +0000
+++ src/util/vfs/vfs-fifo.c
@@ -19,7 +19,7 @@ static void* _vffMap(struct VFile* vf, s
 static void _vffUnmap(struct VFile* vf, void* memory, size_t size);
 static void _vffTruncate(struct VFile* vf, size_t size);
 static ssize_t _vffSize(struct VFile* vf);
-static bool _vffSync(struct VFile* vf, const void* buffer, size_t size);
+static bool _vffSync(struct VFile* vf, void* buffer, size_t size);
 
 struct VFile* VFileFIFO(struct CircleBuffer* backing) {
 	if (!backing) {
@@ -94,7 +94,7 @@ static ssize_t _vffSize(struct VFile* vf
 	return CircleBufferSize(vff->backing);
 }
 
-static bool _vffSync(struct VFile* vf, const void* buffer, size_t size) {
+static bool _vffSync(struct VFile* vf, void* buffer, size_t size) {
 	UNUSED(vf);
 	UNUSED(buffer);
 	UNUSED(size);
