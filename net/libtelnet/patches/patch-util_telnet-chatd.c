$NetBSD: patch-util_telnet-chatd.c,v 1.1 2016/04/30 20:18:38 joerg Exp $

Uses strdup.

--- util/telnet-chatd.c.orig	2016-04-27 08:59:27.691493917 +0000
+++ util/telnet-chatd.c
@@ -10,6 +10,7 @@
  */
 
 #if !defined(_WIN32)
+#	define _XOPEN_SOURCE 520
 #	if !defined(_POSIX_SOURCE)
 #		define _POSIX_SOURCE
 #	endif
