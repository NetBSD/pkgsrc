$NetBSD: patch-util_telnet-chatd.c,v 1.2 2019/03/20 16:02:10 jperkin Exp $

Uses strdup.

--- util/telnet-chatd.c.orig	2012-03-18 21:07:49.000000000 +0000
+++ util/telnet-chatd.c
@@ -10,9 +10,12 @@
  */
 
 #if !defined(_WIN32)
+#  if !defined(__sun) || __STDC_VERSION__-0 < 199901L
+#	define _XOPEN_SOURCE 520
 #	if !defined(_POSIX_SOURCE)
 #		define _POSIX_SOURCE
 #	endif
+#  endif
 #	if !defined(_BSD_SOURCE)
 #		define _BSD_SOURCE
 #	endif
