$NetBSD: patch-lib_engine_presence_presence-core.h,v 1.1 2016/11/20 22:12:19 joerg Exp $

--- lib/engine/presence/presence-core.h.orig	2016-11-20 00:45:43.000000000 +0000
+++ lib/engine/presence/presence-core.h
@@ -38,6 +38,7 @@
 #ifndef __PRESENCE_CORE_H__
 #define __PRESENCE_CORE_H__
 
+#include <vector>
 #include "services.h"
 #include "cluster.h"
 #include "account-core.h"
@@ -309,7 +310,7 @@ namespace Ekiga
 
   private:
 
-    std::set<sigc::slot1<bool, std::string> > uri_testers;
+    std::vector<sigc::slot1<bool, std::string> > uri_testers;
 
     /*** Misc ***/
   public:
