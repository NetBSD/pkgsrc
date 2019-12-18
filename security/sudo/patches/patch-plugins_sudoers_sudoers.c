$NetBSD: patch-plugins_sudoers_sudoers.c,v 1.1 2019/12/18 15:56:11 kim Exp $

Indicate the resource for which get/setrlimit fails.
Make the code match what src/limits.c does.

--- plugins/sudoers/sudoers.c.orig	2019-10-28 14:28:53.000000000 +0200
+++ plugins/sudoers/sudoers.c	2019-12-18 15:41:53.019149463 +0200
@@ -123,16 +123,15 @@
 unlimit_nproc(void)
 {
 #ifdef __linux__
-    struct rlimit rl;
+    struct rlimit rl = { RLIM_INFINITY, RLIM_INFINITY };
     debug_decl(unlimit_nproc, SUDOERS_DEBUG_UTIL)
 
     if (getrlimit(RLIMIT_NPROC, &nproclimit) != 0)
-	    sudo_warn("getrlimit");
-    rl.rlim_cur = rl.rlim_max = RLIM_INFINITY;
-    if (setrlimit(RLIMIT_NPROC, &rl) != 0) {
+	sudo_warn("getrlimit(RLIMIT_NPROC)");
+    if (setrlimit(RLIMIT_NPROC, &rl) == -1) {
 	rl.rlim_cur = rl.rlim_max = nproclimit.rlim_max;
 	if (setrlimit(RLIMIT_NPROC, &rl) != 0)
-	    sudo_warn("setrlimit");
+	    sudo_warn("setrlimit(RLIMIT_NPROC)");
     }
     debug_return;
 #endif /* __linux__ */
@@ -148,7 +147,7 @@
     debug_decl(restore_nproc, SUDOERS_DEBUG_UTIL)
 
     if (setrlimit(RLIMIT_NPROC, &nproclimit) != 0)
-	sudo_warn("setrlimit");
+	sudo_warn("setrlimit(RLIMIT_NPROC)");
 
     debug_return;
 #endif /* __linux__ */
