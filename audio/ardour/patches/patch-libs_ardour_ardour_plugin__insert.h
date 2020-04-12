$NetBSD: patch-libs_ardour_ardour_plugin__insert.h,v 1.1 2020/04/12 19:36:26 joerg Exp $

Ensure operators are defined in the namespace of one of the arguments.

--- libs/ardour/ardour/plugin_insert.h.orig	2020-04-11 23:36:29.754327360 +0000
+++ libs/ardour/ardour/plugin_insert.h
@@ -386,8 +386,8 @@ class LIBARDOUR_API PluginInsert : publi
 	void preset_load_set_value (uint32_t, float);
 };
 
-} // namespace ARDOUR
+std::ostream& operator<<(std::ostream& o, const PluginInsert::Match& m);
 
-std::ostream& operator<<(std::ostream& o, const ARDOUR::PluginInsert::Match& m);
+} // namespace ARDOUR
 
 #endif /* __ardour_plugin_insert_h__ */
