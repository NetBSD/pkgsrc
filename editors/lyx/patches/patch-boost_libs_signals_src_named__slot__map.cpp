$NetBSD: patch-boost_libs_signals_src_named__slot__map.cpp,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- boost/libs/signals/src/named_slot_map.cpp.orig	2013-05-09 11:30:54.000000000 +0000
+++ boost/libs/signals/src/named_slot_map.cpp
@@ -102,7 +102,7 @@ void named_slot_map::disconnect(const st
       i->first.disconnect();
       i = next;
     }
-    groups.erase(group);
+    groups.erase(const_group_iterator(group));
   }
 }
 
@@ -125,7 +125,7 @@ void named_slot_map::remove_disconnected
     }
 
     // Clear out empty groups
-    if (empty(g)) groups.erase(g++);
+    if (empty(g)) groups.erase(const_group_iterator(g++));
     else ++g;
   }
 }
