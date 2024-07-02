$NetBSD: patch-sandbox-darwin.c,v 1.2.68.1 2024/07/02 06:32:11 bsiegert Exp $

Support sandbox on newer OSX, from MacPorts.
https://github.com/macports/macports-ports/blob/master/net/openssh/files/patch-sandbox-darwin.c-apple-sandbox-named-external.diff

--- sandbox-darwin.c.orig	2024-07-01 04:36:28.000000000 +0000
+++ sandbox-darwin.c
@@ -63,8 +63,16 @@ ssh_sandbox_child(struct ssh_sandbox *bo
 	struct rlimit rl_zero;
 
 	debug3("%s: starting Darwin sandbox", __func__);
+#ifdef __APPLE_SANDBOX_NAMED_EXTERNAL__
+#ifndef SANDBOX_NAMED_EXTERNAL
+#define SANDBOX_NAMED_EXTERNAL (0x3)
+#endif
+	if (sandbox_init("@PKG_SYSCONFDIR@/org.openssh.sshd.sb",
+	    SANDBOX_NAMED_EXTERNAL, &errmsg) == -1)
+#else
 	if (sandbox_init(kSBXProfilePureComputation, SANDBOX_NAMED,
 	    &errmsg) == -1)
+#endif
 		fatal("%s: sandbox_init: %s", __func__, errmsg);
 
 	/*
