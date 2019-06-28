$NetBSD: patch-src_mongo_db_repl_master__slave.cpp,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/mongo/db/repl/master_slave.cpp.orig	2017-07-11 17:40:23.338075821 +0000
+++ src/mongo/db/repl/master_slave.cpp
@@ -45,6 +45,7 @@
 #include "mongo/db/repl/master_slave.h"
 
 #include <pcrecpp.h>
+#include <string>
 
 #include "mongo/db/auth/authorization_manager.h"
 #include "mongo/db/auth/authorization_session.h"
@@ -78,6 +79,7 @@ using std::endl;
 using std::max;
 using std::min;
 using std::set;
+using std::string;
 using std::stringstream;
 using std::unique_ptr;
 using std::vector;
