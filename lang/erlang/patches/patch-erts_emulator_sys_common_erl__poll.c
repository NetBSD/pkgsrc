$NetBSD: patch-erts_emulator_sys_common_erl__poll.c,v 1.1 2016/12/17 23:27:23 joerg Exp $

Do not depend on defined() being evaluated in a macro expansion.

--- erts/emulator/sys/common/erl_poll.c.orig	2016-12-16 13:31:54.163364875 +0000
+++ erts/emulator/sys/common/erl_poll.c
@@ -148,11 +148,17 @@ int ERTS_SELECT(int nfds, ERTS_fd_set *r
 
 #define ERTS_POLL_USE_BATCH_UPDATE_POLLSET (ERTS_POLL_USE_DEVPOLL \
 					    || ERTS_POLL_USE_KQUEUE)
-#define ERTS_POLL_USE_UPDATE_REQUESTS_QUEUE \
-   (defined(ERTS_SMP) || ERTS_POLL_USE_KERNEL_POLL || ERTS_POLL_USE_POLL)
+#if (defined(ERTS_SMP) || ERTS_POLL_USE_KERNEL_POLL || ERTS_POLL_USE_POLL)
+#define ERTS_POLL_USE_UPDATE_REQUESTS_QUEUE 1
+#else
+#define ERTS_POLL_USE_UPDATE_REQUESTS_QUEUE 0
+#endif
 
-#define ERTS_POLL_USE_CONCURRENT_UPDATE \
-   (defined(ERTS_SMP) && ERTS_POLL_USE_EPOLL)
+#if (defined(ERTS_SMP) && ERTS_POLL_USE_EPOLL)
+#define ERTS_POLL_USE_CONCURRENT_UPDATE 1
+#else
+#define ERTS_POLL_USE_CONCURRENT_UPDATE 0
+#endif
 
 #define ERTS_POLL_COALESCE_KP_RES (ERTS_POLL_USE_KQUEUE || ERTS_POLL_USE_EPOLL)
 
@@ -162,8 +168,11 @@ int ERTS_SELECT(int nfds, ERTS_fd_set *r
 #  define ERTS_POLL_ASYNC_INTERRUPT_SUPPORT 0
 #endif
 
-#define ERTS_POLL_USE_WAKEUP_PIPE \
-   (ERTS_POLL_ASYNC_INTERRUPT_SUPPORT || defined(USE_THREADS))
+#if (ERTS_POLL_ASYNC_INTERRUPT_SUPPORT || defined(USE_THREADS))
+#define ERTS_POLL_USE_WAKEUP_PIPE 1
+#else
+#define ERTS_POLL_USE_WAKEUP_PIPE 0
+#endif
 
 #ifdef ERTS_SMP
 
