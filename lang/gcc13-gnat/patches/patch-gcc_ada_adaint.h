$NetBSD: patch-gcc_ada_adaint.h,v 1.3 2025/10/15 20:04:57 dkazankov Exp $

Due to the lack of symbol versioning in NetBSD, some functions need
to be exported from C to be used correctly.

--- gcc/ada/adaint.h.orig	2025-06-05 19:02:58.000000000 +0300
+++ gcc/ada/adaint.h
@@ -348,6 +348,26 @@
 
 extern const void * __gnat_get_executable_load_address  (void);
 
+#if defined(__NetBSD__)
+#include <signal.h>
+extern int    __gnat_sigemptyset (sigset_t *);
+extern int    __gnat_sigfillset  (sigset_t *);
+extern int    __gnat_sigaddset   (sigset_t *, int);
+extern int    __gnat_sigdelset   (sigset_t *, int);
+extern int    __gnat_sigismember (sigset_t *, int);
+extern int    __gnat_sigaltstack (const stack_t *, stack_t *);
+extern int    __gnat_sigaction   (int, const struct sigaction *, struct sigaction *);
+#include <time.h>
+extern int    __gnat_nanosleep     (const struct timespec *, struct timespec *);
+extern int    __gnat_gettimeofday  (struct timeval *, struct timezone *);
+#include <sys/select.h>
+extern int    __gnat_select        (int, fd_set *, fd_set *, fd_set *, struct timeval *);
+#include <sys/socket.h>
+extern int    __gnat_socket        (int, int, int);
+extern int    __gnat_clock_getres  (clockid_t, struct timespec *);
+extern int    __gnat_clock_gettime (clockid_t, struct timespec *);
+#endif
+
 #ifdef __cplusplus
 }
 #endif
