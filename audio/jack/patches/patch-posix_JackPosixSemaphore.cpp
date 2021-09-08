$NetBSD: patch-posix_JackPosixSemaphore.cpp,v 1.1 2021/09/08 19:19:20 nia Exp $

NetBSD requires POSIX semaphores to be prefixed with
a slash, see sem_open(3).

--- posix/JackPosixSemaphore.cpp.orig	2021-07-15 06:18:26.000000000 +0000
+++ posix/JackPosixSemaphore.cpp
@@ -46,13 +46,13 @@ void JackPosixSemaphore::BuildName(const
 {
     char ext_client_name[SYNC_MAX_NAME_SIZE + 1];
     JackTools::RewriteName(client_name, ext_client_name);
-#if __APPLE__  // POSIX semaphore names are limited to 32 characters... 
+#if __APPLE__  // POSIX semaphore names are limited to 32 characters...
     snprintf(res, 32, "js_%s", ext_client_name); 
 #else
     if (fPromiscuous) {
-        snprintf(res, size, "jack_sem.%s_%s", server_name, ext_client_name);
+        snprintf(res, size, "/jack_sem.%s_%s", server_name, ext_client_name);
     } else {
-        snprintf(res, size, "jack_sem.%d_%s_%s", JackTools::GetUID(), server_name, ext_client_name);
+        snprintf(res, size, "/jack_sem.%d_%s_%s", JackTools::GetUID(), server_name, ext_client_name);
     }
 #endif
 }
