$NetBSD: patch-vio_viosocket.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* don't use kqueue on older NetBSD which misses EVFILT_USER

$NetBSD: patch-vio_viosocket.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

--- vio/viosocket.cc.orig	2021-03-22 08:44:50.000000000 +0000
+++ vio/viosocket.cc
@@ -70,6 +70,10 @@
 
 #include "mysql/psi/mysql_socket.h"
 
+#if defined(HAVE_QUEUE) && !defined(EVFILT_USER)
+#undef HAVE_KQUEUE
+#endif
+
 int vio_errno(Vio *vio MY_ATTRIBUTE((unused))) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
