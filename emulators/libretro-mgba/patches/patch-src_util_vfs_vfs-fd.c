$NetBSD: patch-src_util_vfs_vfs-fd.c,v 1.1 2018/09/07 18:54:02 nia Exp $

Define _BSD_SOURCE for futimes().

msync's argument is a non-const void pointer, so don't needlessly
convert to const then discard it.

--- src/util/vfs/vfs-fd.c.orig	2018-04-14 20:49:19.000000000 +0000
+++ src/util/vfs/vfs-fd.c
@@ -3,6 +3,11 @@
  * This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+#define _BSD_SOURCE /* futimes */
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE /* futimes */
+#endif
+
 #include <mgba-util/vfs.h>
 
 #include <fcntl.h>
@@ -30,7 +35,7 @@ static void* _vfdMap(struct VFile* vf, s
 static void _vfdUnmap(struct VFile* vf, void* memory, size_t size);
 static void _vfdTruncate(struct VFile* vf, size_t size);
 static ssize_t _vfdSize(struct VFile* vf);
-static bool _vfdSync(struct VFile* vf, const void* buffer, size_t size);
+static bool _vfdSync(struct VFile* vf, void* buffer, size_t size);
 
 struct VFile* VFileOpenFD(const char* path, int flags) {
 	if (!path) {
@@ -161,7 +166,7 @@ static ssize_t _vfdSize(struct VFile* vf
 	return stat.st_size;
 }
 
-static bool _vfdSync(struct VFile* vf, const void* buffer, size_t size) {
+static bool _vfdSync(struct VFile* vf, void* buffer, size_t size) {
 	UNUSED(buffer);
 	UNUSED(size);
 	struct VFileFD* vfd = (struct VFileFD*) vf;
