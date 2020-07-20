$NetBSD: patch-examples_sshd__direct-tcpip.c,v 1.1 2020/07/20 15:56:24 micha Exp $

Build fix:
Include header files with declarations for struct sockaddr_in and send().

--- examples/sshd_direct-tcpip.c.orig	2020-01-27 15:45:32.000000000 +0000
+++ examples/sshd_direct-tcpip.c
@@ -20,6 +20,9 @@ clients must be made or how a client sho
 
 #include "config.h"
 
+#include <netinet/in.h>  /* For struct sockaddr_in */
+#include <sys/socket.h>  /* For send() */
+
 #include <libssh/libssh.h>
 #include <libssh/server.h>
 #include <libssh/callbacks.h>
