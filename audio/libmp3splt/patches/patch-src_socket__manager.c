$NetBSD: patch-src_socket__manager.c,v 1.2 2013/07/10 14:44:53 ryoon Exp $

--- src/socket_manager.c.orig	2013-02-08 09:21:53.000000000 +0000
+++ src/socket_manager.c
@@ -48,6 +48,8 @@ Manages a socket connection
 
 #ifdef __WIN32__
 #include <malloc.h>
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
