$NetBSD: patch-lib_isc_unix_socket.c,v 1.3 2019/10/24 12:50:36 otis Exp $

* Apply fixes from NetBSD base system.
* Fix build on SmartOS. In this special case, _XOPEN_SOURCE has to be only
  defined on SmartOS.

--- lib/isc/unix/socket.c.orig	2019-10-02 06:24:10.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -11,6 +11,15 @@
 
 /*! \file */
 
+/* needed for CMSG_DATA */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include <config.h>
 
 #include <inttypes.h>
@@ -225,6 +234,7 @@ typedef enum { poll_idle, poll_active, p
 			 (e) == EWOULDBLOCK || \
 			 (e) == ENOBUFS || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
