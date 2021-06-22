$NetBSD: patch-vio_viosocket.cc,v 1.2 2021/06/22 10:12:37 nia Exp $

* define ppoll on older NetBSD that only has pollts

--- vio/viosocket.cc.orig	2021-03-22 08:44:50.000000000 +0000
+++ vio/viosocket.cc
@@ -70,6 +70,13 @@
 
 #include "mysql/psi/mysql_socket.h"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if !__NetBSD_Prereq__(9,99,71)
+#define ppoll pollts
+#endif
+#endif
+
 int vio_errno(Vio *vio MY_ATTRIBUTE((unused))) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
