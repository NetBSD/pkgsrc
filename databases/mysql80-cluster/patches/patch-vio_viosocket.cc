$NetBSD: patch-vio_viosocket.cc,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- vio/viosocket.cc.orig	2022-03-23 13:49:36.000000000 +0000
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
