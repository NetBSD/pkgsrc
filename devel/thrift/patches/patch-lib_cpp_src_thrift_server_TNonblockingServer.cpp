$NetBSD: patch-lib_cpp_src_thrift_server_TNonblockingServer.cpp,v 1.1 2019/09/18 11:27:53 adam Exp $

Need strings.h for bzero().

--- lib/cpp/src/thrift/server/TNonblockingServer.cpp.orig	2017-12-03 19:11:36.000000000 +0000
+++ lib/cpp/src/thrift/server/TNonblockingServer.cpp
@@ -75,6 +75,10 @@
 #include <stdint.h>
 #endif
 
+#ifdef HAVE_STRINGS_H
+#include <strings.h>
+#endif
+
 namespace apache {
 namespace thrift {
 namespace server {
