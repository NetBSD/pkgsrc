$NetBSD: patch-lib-src_libnyquist_nyquist_xlisp_security.c,v 1.1 2025/09/29 20:52:04 mrg Exp $

Ensure unistd.h is included on NetBSD.
Fix ctype-abuse.

--- lib-src/libnyquist/nyquist/xlisp/security.c.orig	2020-05-19 02:43:53.000000000 -0700
+++ lib-src/libnyquist/nyquist/xlisp/security.c	2025-09-25 13:14:10.427474354 -0700
@@ -4,7 +4,7 @@
  */
 
 #include <stdlib.h>
-#if defined(UNIX) || defined(__APPLE__)
+#if defined(UNIX) || defined(__APPLE__) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 #ifdef WIN32
@@ -142,7 +142,7 @@
     /* windows allows '/' instead of '\' */
     if (filename[0] == '/') return TRUE;
     if (strlen(filename) > 2 &&
-	isalpha(filename[0]) &&
+	isalpha((unsigned char)filename[0]) &&
 	filename[1] == ':') return TRUE;
     return FALSE;
 }
