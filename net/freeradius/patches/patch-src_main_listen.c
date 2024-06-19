$NetBSD: patch-src_main_listen.c,v 1.2 2024/06/19 08:46:33 adam Exp $

Fix missing SOL_TCP for other platforms.

--- src/main/listen.c.orig	2024-05-29 16:18:18.000000000 +0000
+++ src/main/listen.c
@@ -55,7 +55,7 @@ RCSID("$Id: dbb2167e28189720df35cbf677ff
 #ifdef WITH_TLS
 #include <netinet/tcp.h>
 
-#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__illumos__) || defined(__sun__)
+#  if defined(__APPLE__) || defined(__FreeBSD__) || defined(__illumos__) || defined(__sun__) || defined(__NetBSD__)
 #    if !defined(SOL_TCP) && defined(IPPROTO_TCP)
 #      define SOL_TCP IPPROTO_TCP
 #    endif
