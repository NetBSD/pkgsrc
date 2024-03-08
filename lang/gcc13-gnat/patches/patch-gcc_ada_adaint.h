$NetBSD: patch-gcc_ada_adaint.h,v 1.1 2024/03/08 12:02:33 wiz Exp $

Due to the lack of symbol versioning in NetBSD, some functions need
to be exported from C to be used correctly. This patch addresses
that issue and makes sure that other systems also work correclty.

--- gcc/ada/adaint.h.orig	2021-10-09 19:21:39.117755578 +0200
+++ gcc/ada/adaint.h	2021-10-09 19:02:38.871872061 +0200
@@ -345,6 +345,28 @@
 
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
+#endif
+#include <time.h>
+extern int    __gnat_nanosleep     (const struct timespec *, struct timespec *);
+extern int    __gnat_gettimeofday  (struct timeval *, struct timezone *);
+#include <sys/select.h>
+extern int    __gnat_select        (int, fd_set *, fd_set *, fd_set *, struct timeval *);
+#include <sys/socket.h>
+extern int    __gnat_socket        (int, int, int);
+#if defined(__NetBSD__)
+extern int    __gnat_clock_getres  (clockid_t, struct timespec *);
+extern int    __gnat_clock_gettime (clockid_t, struct timespec *);
+#endif
+
 #ifdef __cplusplus
 }
 #endif
