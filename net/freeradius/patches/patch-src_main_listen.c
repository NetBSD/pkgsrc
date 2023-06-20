$NetBSD: patch-src_main_listen.c,v 1.1 2023/06/20 08:38:09 adam Exp $

Fix missing SOL_TCP for other platforms.

--- src/main/listen.c.orig	2023-06-20 08:35:52.487727610 +0000
+++ src/main/listen.c
@@ -55,11 +55,9 @@ RCSID("$Id: ee73a571aedb81939bb72ac36b65
 #ifdef WITH_TLS
 #include <netinet/tcp.h>
 
-#  ifdef __APPLE__
 #    if !defined(SOL_TCP) && defined(IPPROTO_TCP)
 #      define SOL_TCP IPPROTO_TCP
 #    endif
-#  endif
 
 #endif
 
