$NetBSD: patch-lib_readline_rlprivate.h,v 1.1 2025/10/10 20:48:02 js Exp $

--- lib/readline/rlprivate.h.orig	2025-03-07 23:51:02.000000000 +0000
+++ lib/readline/rlprivate.h
@@ -344,6 +344,8 @@ extern int _rl_timeout_handle_sigalrm (v
 
 #endif
 #if defined (RL_TIMEOUT_USE_SELECT)
+#include <signal.h>
+#include <sys/select.h>
 extern int _rl_timeout_select (int, fd_set *, fd_set *, fd_set *, const struct timeval *, const sigset_t *);
 #endif
 
