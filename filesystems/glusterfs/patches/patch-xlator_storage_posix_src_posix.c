$NetBSD: patch-xlator_storage_posix_src_posix.c,v 1.1 2014/11/18 14:38:15 manu Exp $

Shut up log-filling message

--- xlators/storage/posix/src/posix.c.orig	2014-11-04 14:29:56.000000000 +0100
+++ xlators/storage/posix/src/posix.c	2014-11-04 14:30:49.000000000 +0100
@@ -3431,9 +3431,9 @@
                                         &nlink_samepgfid,
                                         sizeof(nlink_samepgfid));
                 if (op_ret == -1) {
                         *op_errno = errno;
-                        gf_log (this->name, GF_LOG_ERROR,
+                        gf_log (this->name, GF_LOG_DEBUG,
                                 "getxattr failed on "
                                 "%s: key = %s (%s)",
                                 leaf_path,
                                 key,
