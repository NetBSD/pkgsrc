$NetBSD: patch-src_lib_torsocks.c,v 1.1 2018/11/20 23:42:59 leot Exp $

LIBC_ACCEPT4_* is defined only on Linux.

--- src/lib/torsocks.c.orig	2018-04-20 15:41:42.000000000 +0000
+++ src/lib/torsocks.c
@@ -234,9 +234,15 @@ static void init_libc_symbols(void)
 	tsocks_libc_socket = dlsym(libc_ptr, LIBC_SOCKET_NAME_STR);
 	tsocks_libc_syscall = dlsym(libc_ptr, LIBC_SYSCALL_NAME_STR);
 	tsocks_libc_execve = dlsym(libc_ptr, LIBC_EXECVE_NAME_STR);
+#ifdef LIBC_ACCEPT4_NAME_STR
 	tsocks_libc_accept4 = dlsym(libc_ptr, LIBC_ACCEPT4_NAME_STR);
+#endif
 	if (!tsocks_libc_connect || !tsocks_libc_close || !tsocks_libc_socket ||
-			!tsocks_libc_syscall || !tsocks_libc_execve || ! tsocks_libc_accept4) {
+			!tsocks_libc_syscall || !tsocks_libc_execve
+#ifdef LIBC_ACCEPT4_NAME_STR
+			|| !tsocks_libc_accept4
+#endif
+			) {
 		ERR("Unable to lookup symbols in " LIBC_NAME "(%s)", dlerror());
 		goto error;
 	}
