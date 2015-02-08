$NetBSD: patch-hotspot_src_share_vm_opto_node.cpp,v 1.1 2015/02/08 08:41:25 tnn Exp $

--- hotspot/src/share/vm/opto/node.cpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/share/vm/opto/node.cpp
@@ -291,6 +291,10 @@ void DUIterator_Last::verify_step(uint n
 #pragma GCC diagnostic ignored "-Wuninitialized"
 #endif
 
+#ifdef __GNUC__
+#pragma GCC diagnostic ignored "-Wuninitialized"
+#endif
+
 // Out-of-line code from node constructors.
 // Executed only when extra debug info. is being passed around.
 static void init_node_notes(Compile* C, int idx, Node_Notes* nn) {
