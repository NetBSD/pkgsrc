$NetBSD: patch-src_main_listen.c,v 1.3 2024/07/24 14:28:05 manu Exp $

Fix missing SOL_TCP for other platforms.

--- src/main/listen.c.orig	2024-07-08 22:29:24.000000000 +0200
+++ src/main/listen.c	2024-07-19 15:39:10.917760544 +0200
@@ -54,9 +54,9 @@
 
 #ifdef WITH_TLS
 #include <netinet/tcp.h>
 
-#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__illumos__) || defined(__sun__)
+#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__illumos__) || defined(__sun__)
 #    if !defined(SOL_TCP) && defined(IPPROTO_TCP)
 #      define SOL_TCP IPPROTO_TCP
 #    endif
 #  endif
