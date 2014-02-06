$NetBSD: patch-src_emu_netlist_pstate.h,v 1.1 2014/02/06 10:40:19 wiz Exp $

clang fixes from upstream SVN 26743.

--- src/emu/netlist/pstate.h.orig	2013-12-24 08:24:52.000000000 +0000
+++ src/emu/netlist/pstate.h
@@ -15,11 +15,15 @@
 // state saving ...
 // ----------------------------------------------------------------------------------------
 
-#define PSTATE_INTERFACE(manager, module)               \
-	template<class C> ATTR_COLD void save(C &state, const pstring &stname) \
+#define PSTATE_INTERFACE_DECL()               \
+    template<typename C> ATTR_COLD void save(C &state, const pstring &stname);
+
+#define PSTATE_INTERFACE(obj, manager, module)               \
+    template<typename C> ATTR_COLD void obj::save(C &state, const pstring &stname) \
 	{                                                                       \
-		dynamic_cast<pstate_manager_t &>(manager).save_manager(state, module + "." + stname);  \
+        manager->save_manager(state, module + "." + stname);  \
 	}
+ 
 
 enum netlist_data_type_e {
 	NOT_SUPPORTED,
