$NetBSD: patch-lib_cpp_src_thrift_transport_SocketCommon.cpp,v 1.2 2025/03/04 13:05:20 adam Exp $

Include string.h for memcpy().

--- lib/cpp/src/thrift/transport/SocketCommon.cpp.orig	2024-03-18 20:28:38.000000000 +0000
+++ lib/cpp/src/thrift/transport/SocketCommon.cpp
@@ -24,6 +24,9 @@
 #include <thrift/transport/TTransportException.h>
 #include <thrift/TOutput.h>
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #include <cstring>
 
 namespace apache {
