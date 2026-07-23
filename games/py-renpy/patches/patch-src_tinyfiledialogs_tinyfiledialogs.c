$NetBSD: patch-src_tinyfiledialogs_tinyfiledialogs.c,v 1.1 2026/07/23 14:03:50 ryoon Exp $

* Do not segfault under NetBSD.

--- src/tinyfiledialogs/tinyfiledialogs.c.orig	2023-11-23 13:03:29.419445256 +0000
+++ src/tinyfiledialogs/tinyfiledialogs.c
@@ -56,7 +56,7 @@ Thanks for contributions, bug correction
 
 #if !defined(_WIN32) && ( defined(__GNUC__) || defined(__clang__) )
 #if !defined(_GNU_SOURCE)
- #define _GNU_SOURCE /* used only to resolve symbolic links. Can be commented out */
+// #define _GNU_SOURCE /* used only to resolve symbolic links. Can be commented out */
 #endif
 #endif
 
