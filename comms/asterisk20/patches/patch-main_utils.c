$NetBSD: patch-main_utils.c,v 1.2 2024/10/26 13:12:23 ryoon Exp $

--- main/utils.c.orig	2024-10-17 16:00:41.000000000 +0000
+++ main/utils.c
@@ -937,7 +937,7 @@ const char *ast_inet_ntoa(struct in_addr
 
 static int dev_urandom_fd = -1;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #undef pthread_create /* For ast_pthread_create function only */
 #endif /* !__linux__ */
 
