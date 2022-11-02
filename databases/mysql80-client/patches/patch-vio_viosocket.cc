$NetBSD: patch-vio_viosocket.cc,v 1.3 2022/11/02 17:02:10 jperkin Exp $

* define ppoll on older NetBSD that only has pollts

--- vio/viosocket.cc.orig	2022-09-13 16:15:16.000000000 +0000
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
 int vio_errno(Vio *vio [[maybe_unused]]) {
 /* These transport types are not Winsock based. */
 #ifdef _WIN32
