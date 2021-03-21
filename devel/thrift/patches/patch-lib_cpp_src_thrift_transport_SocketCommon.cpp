$NetBSD: patch-lib_cpp_src_thrift_transport_SocketCommon.cpp,v 1.1 2021/03/21 12:41:11 taca Exp $

Need string.h for memcpy().

--- lib/cpp/src/thrift/transport/SocketCommon.cpp.orig	2021-02-04 23:07:31.000000000 +0000
+++ lib/cpp/src/thrift/transport/SocketCommon.cpp
@@ -34,6 +34,10 @@
 #include <sys/un.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 #include <string>
 
 #include <thrift/transport/PlatformSocket.h>
