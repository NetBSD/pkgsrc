$NetBSD: patch-src_socket__manager.c,v 1.1 2013/07/05 16:14:13 ryoon Exp $

--- src/socket_manager.c.orig	2013-02-08 09:21:53.000000000 +0000
+++ src/socket_manager.c
@@ -48,8 +48,10 @@ Manages a socket connection
 
 #ifdef __WIN32__
 #include <malloc.h>
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#include <stdlib.h>
 #else
-#include <alloca.h>
+include <alloca.h>
 #endif
 
 #include <string.h>
