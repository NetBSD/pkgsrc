$NetBSD: patch-pim_xrl__pim__node.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- pim/xrl_pim_node.hh.orig	2020-04-16 15:10:54.106155087 +0000
+++ pim/xrl_pim_node.hh
@@ -22,6 +22,10 @@
 #ifndef __PIM_XRL_PIM_NODE_HH__
 #define __PIM_XRL_PIM_NODE_HH__
 
+#ifdef __NetBSD__
+#include <net/if.h>
+#undef if_name
+#endif
 
 //
 // PIM XRL-aware node definition.
