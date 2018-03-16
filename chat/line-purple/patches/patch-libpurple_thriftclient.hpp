$NetBSD: patch-libpurple_thriftclient.hpp,v 1.1 2018/03/16 21:06:31 scole Exp $

std::make_shared does not seem to compile on NetBSD so use boost::make_shared

--- libpurple/thriftclient.hpp.orig	2018-02-21 13:01:04.000000000 -0800
+++ libpurple/thriftclient.hpp		2018-03-16 09:45:53.000000000 -0700
@@ -3,6 +3,9 @@
 #include <string>
 #include <deque>
 
+#include <boost/shared_ptr.hpp>
+#include <boost/make_shared.hpp>
+
 #include <debug.h>
 #include <plugin.h>
 #include <prpl.h>
@@ -14,7 +17,7 @@
 class ThriftClient : public line::TalkServiceClient {
 
     std::string path;
-    std::shared_ptr<LineHttpTransport> http;
+    boost::shared_ptr<LineHttpTransport> http;
 
 public:
 
