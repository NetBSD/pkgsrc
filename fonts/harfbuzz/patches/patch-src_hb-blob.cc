$NetBSD: patch-src_hb-blob.cc,v 1.3 2019/02/14 17:43:32 abs Exp $

Do not play _POSIX_C_SOURCE games on NetBSD.
Avoids issues with building under pkgsrc gcc versions

--- src/hb-blob.cc.orig	2019-01-29 21:39:07.000000000 +0000
+++ src/hb-blob.cc
@@ -30,7 +30,7 @@
  * http://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
  * https://www.oracle.com/technetwork/articles/servers-storage-dev/standardheaderfiles-453865.html
  */
-#ifndef _POSIX_C_SOURCE
+#if !defined (_POSIX_C_SOURCE) && !defined (__NetBSD__)
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wunused-macros"
 #define _POSIX_C_SOURCE 200809L
