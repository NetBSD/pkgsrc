$NetBSD: patch-util_telnet-proxy.c,v 1.1 2016/04/30 20:18:38 joerg Exp $

Uses getaddrinfo and friends.

--- util/telnet-proxy.c.orig	2016-04-27 08:57:41.984443954 +0000
+++ util/telnet-proxy.c
@@ -10,6 +10,7 @@
  */
 
 #if !defined(_WIN32)
+#	define _XOPEN_SOURCE 520
 #	if !defined(_POSIX_SOURCE)
 #		define _POSIX_SOURCE
 #	endif
