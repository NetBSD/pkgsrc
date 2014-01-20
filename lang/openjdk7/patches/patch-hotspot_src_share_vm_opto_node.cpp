$NetBSD: patch-hotspot_src_share_vm_opto_node.cpp,v 1.1 2014/01/20 19:25:11 joerg Exp $

--- hotspot/src/share/vm/opto/node.cpp.orig	2014-01-06 00:27:19.000000000 +0000
+++ hotspot/src/share/vm/opto/node.cpp
@@ -285,6 +285,10 @@ void DUIterator_Last::verify_step(uint n
 #pragma warning( disable:4355 ) // 'this' : used in base member initializer list
 #endif
 
+#ifdef __GNUC__
+#pragma GCC diagnostic ignored "-Wuninitialized"
+#endif
+
 // Out-of-line code from node constructors.
 // Executed only when extra debug info. is being passed around.
 static void init_node_notes(Compile* C, int idx, Node_Notes* nn) {
