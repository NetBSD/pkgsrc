$NetBSD: patch-src_rpc_command__scheduler.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/rpc/command_scheduler.cc.orig	2013-05-03 22:51:00.000000000 +0000
+++ src/rpc/command_scheduler.cc
@@ -71,7 +71,7 @@ CommandScheduler::insert(const std::stri
     delete *itr;
 
   *itr = new CommandSchedulerItem(key);
-  (*itr)->slot() = std::tr1::bind(&CommandScheduler::call_item, this, *itr);
+  (*itr)->slot() = bind(&CommandScheduler::call_item, this, *itr);
 
   return itr;
 }
