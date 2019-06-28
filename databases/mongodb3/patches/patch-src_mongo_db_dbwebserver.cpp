$NetBSD: patch-src_mongo_db_dbwebserver.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/db/dbwebserver.cpp.orig	2017-07-11 17:07:27.098292902 +0000
+++ src/mongo/db/dbwebserver.cpp
@@ -35,6 +35,7 @@
 
 #include "mongo/db/dbwebserver.h"
 
+#include <string>
 #include <pcrecpp.h>
 
 #include "mongo/base/init.h"
@@ -67,6 +68,7 @@ namespace mongo {
 using std::map;
 using std::stringstream;
 using std::vector;
+using std::string;
 
 using namespace html;
 
