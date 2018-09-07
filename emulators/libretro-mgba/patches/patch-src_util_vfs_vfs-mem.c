$NetBSD: patch-src_util_vfs_vfs-mem.c,v 1.1 2018/09/07 18:54:02 nia Exp $

vfs.sync's buffer pointer isn't const.

--- src/util/vfs/vfs-mem.c.orig	2018-04-14 20:49:19.000000000 +0000
+++ src/util/vfs/vfs-mem.c
@@ -28,7 +28,7 @@ static void _vfmUnmap(struct VFile* vf, 
 static void _vfmTruncate(struct VFile* vf, size_t size);
 static void _vfmTruncateNoop(struct VFile* vf, size_t size);
 static ssize_t _vfmSize(struct VFile* vf);
-static bool _vfmSync(struct VFile* vf, const void* buffer, size_t size);
+static bool _vfmSync(struct VFile* vf, void* buffer, size_t size);
 
 struct VFile* VFileFromMemory(void* mem, size_t size) {
 	if (!mem || !size) {
@@ -297,7 +297,7 @@ ssize_t _vfmSize(struct VFile* vf) {
 	return vfm->size;
 }
 
-bool _vfmSync(struct VFile* vf, const void* buffer, size_t size) {
+bool _vfmSync(struct VFile* vf, void* buffer, size_t size) {
 	UNUSED(vf);
 	UNUSED(buffer);
 	UNUSED(size);
