$NetBSD: patch-src_rpc_command__scheduler__item.h,v 1.3 2013/09/18 16:33:09 joerg Exp $

--- src/rpc/command_scheduler_item.h.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/rpc/command_scheduler_item.h
@@ -39,14 +39,20 @@
 
 #include "globals.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/object.h>
 
 namespace rpc {
 
 class CommandSchedulerItem {
 public:
-  typedef std::tr1::function<void ()> slot_void;
+  typedef function<void ()> slot_void;
 
   CommandSchedulerItem(const std::string& key) : m_key(key), m_interval(0) {}
   ~CommandSchedulerItem();
