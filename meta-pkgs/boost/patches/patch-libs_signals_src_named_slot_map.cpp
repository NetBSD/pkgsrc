$NetBSD: patch-libs_signals_src_named_slot_map.cpp,v 1.2 2012/07/02 07:02:26 adam Exp $

--- libs/signals/src/named_slot_map.cpp.orig	2009-11-08 02:48:37.000000000 +0100
+++ libs/signals/src/named_slot_map.cpp	2011-10-24 16:04:24.749105300 +0200
@@ -102,7 +102,7 @@ void named_slot_map::disconnect(const st
       i->first.disconnect();
       i = next;
     }
-    groups.erase(group);
+    groups.erase((const_group_iterator) group);
   }
 }
 
@@ -125,7 +125,7 @@ void named_slot_map::remove_disconnected
     }
 
     // Clear out empty groups
-    if (empty(g)) groups.erase(g++);
+    if (empty(g)) groups.erase((const_group_iterator) g++);
     else ++g;
   }
 }
