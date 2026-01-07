$NetBSD: patch-src_slurmd_slurmd_req.c,v 1.1 2026/01/07 18:30:08 adam Exp $

NetBSD doesn't have setresuid().

--- src/slurmd/slurmd/req.c.orig	2026-01-07 14:15:52.102451833 +0000
+++ src/slurmd/slurmd/req.c
@@ -1578,10 +1578,12 @@ static int _open_as_other(char *path_nam
 		error("%s: uid:%u setgid(%u): %m", __func__, uid, gid);
 		_exit(errno);
 	}
+#if !defined(__APPLE__) && !defined(__NetBSD__)
 	if (setresuid(uid, uid, -1) < 0) {
 		error("%s: setresuid(%u, %u, %d): %m", __func__, uid, uid, -1);
 		_exit(errno);
 	}
+#endif
 
 	if (make_dir) {
 		if (force &&
