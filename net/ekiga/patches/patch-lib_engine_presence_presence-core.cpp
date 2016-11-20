$NetBSD: patch-lib_engine_presence_presence-core.cpp,v 1.1 2016/11/20 22:12:19 joerg Exp $

--- lib/engine/presence/presence-core.cpp.orig	2016-11-20 00:45:55.000000000 +0000
+++ lib/engine/presence/presence-core.cpp
@@ -245,7 +245,7 @@ Ekiga::PresenceCore::is_supported_uri (c
 {
   bool result = false;
 
-  for (std::set<sigc::slot1<bool, std::string> >::const_iterator iter
+  for (std::vector<sigc::slot1<bool, std::string> >::const_iterator iter
 	 = uri_testers.begin ();
        iter != uri_testers.end () && result == false;
        iter++)
@@ -257,7 +257,7 @@ Ekiga::PresenceCore::is_supported_uri (c
 void
 Ekiga::PresenceCore::add_supported_uri (sigc::slot1<bool,std::string> tester)
 {
-  uri_testers.insert (tester);
+  uri_testers.push_back(tester);
 }
 
 void
