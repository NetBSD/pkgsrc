$NetBSD: patch-nfs.c,v 1.1 2026/09/02 18:47:29 maya Exp $

Portability

--- nfs.c.orig	2026-07-24 15:19:36.054976780 +0000
+++ nfs.c
@@ -334,7 +334,7 @@ READ3res *nfsproc3_read_3_svc(READ3args 
         fd = fd_open(path, argp->file, UNFS3_FD_READ, TRUE);
         if (fd != -1) {
             /* read one more to check for eof */
-            res = backend_pread(fd, buf, argp->count + 1, (off64_t)argp->offset);
+            res = backend_pread(fd, buf, argp->count + 1, (off_t)argp->offset);
 
             /* eof if we could not read one more */
             result.READ3res_u.resok.eof = (res <= (int64) argp->count);
@@ -395,7 +395,7 @@ WRITE3res *nfsproc3_write_3_svc(WRITE3ar
         if (fd != -1) {
             res =
                 backend_pwrite(fd, argp->data.data_val, argp->data.data_len,
-                               (off64_t)argp->offset);
+                               (off_t)argp->offset);
 
             /* close for real if not UNSTABLE write */
             if (argp->stable == UNSTABLE)
