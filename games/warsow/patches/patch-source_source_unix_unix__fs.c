$NetBSD: patch-source_source_unix_unix__fs.c,v 1.1 2025/09/29 13:31:29 nia Exp $

- Use portable readdir functions.

--- source/source/unix/unix_fs.c.orig	2025-09-29 08:11:09.741846724 +0000
+++ source/source/unix/unix_fs.c
@@ -38,7 +38,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 
 // Mac OS X and FreeBSD don't know the readdir64 and dirent64
-#if ( defined (__FreeBSD__) || defined (__ANDROID__) || !defined(_LARGEFILE64_SOURCE) )
+#if !defined(__linux__)
 #define readdir64 readdir
 #define dirent64 dirent
 #endif
