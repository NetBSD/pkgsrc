$NetBSD: patch-lib_socket.c,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Directly check for getprotobyname(3) instead of
guessing with OS-specific CPP macros.

--- lib/socket.c.orig	2025-11-14 14:14:24.604057983 +0000
+++ lib/socket.c
@@ -170,7 +170,7 @@ set_tcp_sockopt(int sockfd, int optname,
 {
 	int level;
 
-	#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__sun) || (defined(__APPLE__) && defined(__MACH__))
+	#if defined(HAVE_GETPROTOBYNAME)
 	struct protoent *buf;
 
 	if ((buf = getprotobyname("tcp")) != NULL)
