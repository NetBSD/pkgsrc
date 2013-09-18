$NetBSD: patch-src_rpc_command__scheduler.cc,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/rpc/command_scheduler.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/rpc/command_scheduler.cc
@@ -47,6 +47,14 @@
 #include "command_scheduler_item.h"
 #include "parse_commands.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace rpc {
 
 CommandScheduler::~CommandScheduler() {
@@ -71,7 +79,7 @@ CommandScheduler::insert(const std::stri
     delete *itr;
 
   *itr = new CommandSchedulerItem(key);
-  (*itr)->slot() = std::tr1::bind(&CommandScheduler::call_item, this, *itr);
+  (*itr)->slot() = bind(&CommandScheduler::call_item, this, *itr);
 
   return itr;
 }
