$NetBSD: patch-libs_ardour_plugin__insert.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/plugin_insert.cc.orig	2020-04-12 00:31:11.850055378 +0000
+++ libs/ardour/plugin_insert.cc
@@ -3098,6 +3098,7 @@ PluginInsert::end_touch (uint32_t param_
 	}
 }
 
+namespace ARDOUR {
 std::ostream& operator<<(std::ostream& o, const ARDOUR::PluginInsert::Match& m)
 {
 	switch (m.method) {
@@ -3118,3 +3119,4 @@ std::ostream& operator<<(std::ostream& o
 	o << "\n";
 	return o;
 }
+}
