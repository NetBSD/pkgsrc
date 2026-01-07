$NetBSD: patch-src_common_net.c,v 1.1 2026/01/07 18:30:07 adam Exp $

Support NetBSD.

--- src/common/net.c.orig	2026-01-07 12:14:11.246444708 +0000
+++ src/common/net.c
@@ -547,6 +547,11 @@ extern int net_get_peer(int fd, uid_t *c
 	*cred_uid = cred.uid;
 	*cred_gid = cred.gid;
 	*cred_pid = cred.pid;
+#elif defined(__NetBSD__)
+	struct uucred cred = {
+		.cr_uid = SLURM_AUTH_NOBODY,
+		.cr_groups = { SLURM_AUTH_NOBODY, },
+	};
 #else
 	struct xucred cred = {
 		.cr_uid = SLURM_AUTH_NOBODY,
