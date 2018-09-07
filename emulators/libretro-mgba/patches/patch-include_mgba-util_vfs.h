$NetBSD: patch-include_mgba-util_vfs.h,v 1.1 2018/09/07 18:54:02 nia Exp $

vfs-fd's sync implementation uses msync, which uses a non-const pointer.

--- include/mgba-util/vfs.h.orig	2018-04-14 20:49:19.000000000 +0000
+++ include/mgba-util/vfs.h
@@ -47,7 +47,7 @@ struct VFile {
 	void (*unmap)(struct VFile* vf, void* memory, size_t size);
 	void (*truncate)(struct VFile* vf, size_t size);
 	ssize_t (*size)(struct VFile* vf);
-	bool (*sync)(struct VFile* vf, const void* buffer, size_t size);
+	bool (*sync)(struct VFile* vf, void *buffer, size_t size);
 };
 
 struct VDirEntry {
