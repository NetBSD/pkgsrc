$NetBSD: patch-src-external-heimdal-roken-roken-common.h,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/external/heimdal/roken/roken-common.h.orig	2012-04-30 16:41:30.000000000 -0400
+++ src/external/heimdal/roken/roken-common.h	2012-04-30 17:45:23.000000000 -0400
@@ -335,9 +335,11 @@
 wait_for_process_timed(pid_t, time_t (*)(void *),
 		       void *, time_t);
 
+#ifndef _KERNEL
 #define pipe_execv rk_pipe_execv
 ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL
 pipe_execv(FILE**, FILE**, FILE**, const char*, ...);
+#endif
 
 #define print_version rk_print_version
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
@@ -361,6 +363,7 @@
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 esetenv(const char *, const char *, int);
 
+struct sockaddr;
 #define socket_set_address_and_port rk_socket_set_address_and_port
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 socket_set_address_and_port (struct sockaddr *, const void *, int);
@@ -481,11 +484,13 @@
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec(int);
 
+#ifndef _KERNEL
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec_file(FILE *);
 
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
 rk_cloexec_dir(DIR *);
+#endif
 
 ROKEN_LIB_FUNCTION int ROKEN_LIB_CALL
 ct_memcmp(const void *, const void *, size_t);
