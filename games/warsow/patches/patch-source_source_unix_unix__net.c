$NetBSD: patch-source_source_unix_unix__net.c,v 1.1 2025/09/29 13:31:29 nia Exp $

- Do not try to use sendfile on NetBSD.

--- source/source/unix/unix_net.c.orig	2025-09-29 08:03:23.877952684 +0000
+++ source/source/unix/unix_net.c
@@ -26,7 +26,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <sys/param.h>
 #include <sys/ioctl.h>
 #include <sys/uio.h>
-#if !defined ( __APPLE__ )
+#if !defined ( __APPLE__ ) && !defined(__NetBSD__)
 #include <sys/sendfile.h>
 #endif
 #include <errno.h>
@@ -80,6 +80,9 @@ int Sys_NET_SocketIoctl( socket_handle_t
 */
 int64_t Sys_NET_SendFile( socket_handle_t handle, int fileno, size_t offset, size_t count )
 {
+#if defined ( __NetBSD__ )
+	return -1;
+#else
 	off_t len;
 	off_t _offset = offset;
 #if defined ( __APPLE__ )
@@ -94,6 +97,7 @@ int64_t Sys_NET_SendFile( socket_handle_
 		return result;
 	}
 	return len;
+#endif
 }
 
 //===================================================================
