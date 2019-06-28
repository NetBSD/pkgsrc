$NetBSD: patch-src_mongo_util_net_miniwebserver.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/util/net/miniwebserver.cpp.orig	2017-07-11 17:42:54.304511569 +0000
+++ src/mongo/util/net/miniwebserver.cpp
@@ -33,6 +33,7 @@
 
 #include "mongo/util/net/miniwebserver.h"
 
+#include <string>
 #include <pcrecpp.h>
 
 #include "mongo/config.h"
@@ -45,6 +46,7 @@
 namespace mongo {
 
 using std::shared_ptr;
+using std::string;
 using std::stringstream;
 using std::vector;
 
