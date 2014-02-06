$NetBSD: patch-src_emu_netlist_nl__lists.h,v 1.1 2014/02/06 10:40:19 wiz Exp $

clang fixes from upstream SVN 26917.

--- src/emu/netlist/nl_lists.h.orig	2013-12-24 08:24:52.000000000 +0000
+++ src/emu/netlist/nl_lists.h
@@ -16,7 +16,7 @@
 
 
 template <class _ListClass, int _NumElem = 128>
-struct netlist_list_t
+class netlist_list_t
 {
 public:
 
