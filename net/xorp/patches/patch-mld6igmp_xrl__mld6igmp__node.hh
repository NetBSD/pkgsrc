$NetBSD: patch-mld6igmp_xrl__mld6igmp__node.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- mld6igmp/xrl_mld6igmp_node.hh.orig	2020-04-16 15:02:53.721761291 +0000
+++ mld6igmp/xrl_mld6igmp_node.hh
@@ -22,6 +22,10 @@
 #ifndef __MLD6IGMP_XRL_MLD6IGMP_NODE_HH__
 #define __MLD6IGMP_XRL_MLD6IGMP_NODE_HH__
 
+#ifdef __NetBSD__
+#include <net/if.h>
+#undef if_name
+#endif
 
 //
 // MLD6IGMP XRL-aware node definition.
