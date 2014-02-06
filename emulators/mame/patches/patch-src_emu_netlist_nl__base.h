$NetBSD: patch-src_emu_netlist_nl__base.h,v 1.1 2014/02/06 10:40:19 wiz Exp $

clang fixes from upstream SVN 26743.

--- src/emu/netlist/nl_base.h.orig	2013-12-24 08:24:52.000000000 +0000
+++ src/emu/netlist/nl_base.h
@@ -287,7 +287,7 @@ public:
 
 	ATTR_COLD const pstring &name() const;
 
-	PSTATE_INTERFACE(*m_netlist, name())
+	PSTATE_INTERFACE_DECL()
 
 #if 0
 	template<class C> ATTR_COLD void save(C &state, const pstring &stname)
@@ -1120,6 +1120,8 @@ private:
 // Inline implementations
 // ----------------------------------------------------------------------------------------
 
+PSTATE_INTERFACE(netlist_object_t, m_netlist, name())
+
 ATTR_HOT inline void netlist_param_str_t::setTo(const pstring &param)
 {
 	m_param = param;
