$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_parser_state-processor.cxx,v 1.2 2016/06/07 17:59:51 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/parser/state-processor.cxx.orig	2013-05-14 20:08:50.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/parser/state-processor.cxx
@@ -154,7 +154,8 @@ namespace CXX
               if (++depth > depth_) // One for this compositor.
                 depth_ = depth;
 
-              prefixes_.insert (prefixes_.end (),
+              Particles::EraseIterator e(prefixes_.end ());
+              prefixes_.insert (e,
                                 t.prefixes_.begin ().base (),
                                 t.prefixes_.end ().base ());
 
@@ -231,7 +232,8 @@ namespace CXX
 
               if (prefix)
               {
-                prefixes_.insert (prefixes_.end (),
+                Particles::EraseIterator e(prefixes_.end ());
+                prefixes_.insert (e,
                                   t.prefixes_.begin ().base (),
                                   t.prefixes_.end ().base ());
 
