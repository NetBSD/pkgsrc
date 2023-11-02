$NetBSD: patch-src_node__postmortem__metadata.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

--- src/node_postmortem_metadata.cc.orig	2018-03-23 20:05:49.909811719 +0000
+++ src/node_postmortem_metadata.cc
@@ -11,6 +11,10 @@
 #define NODEDBG_OFFSET(Class, Member, Type) \
     NODEDBG_SYMBOL(offset_ ## Class ## __ ## Member ## __ ## Type)
 
+// Some systems provide macros for the types as well, which get expanded
+// by the nested macros here.
+#undef uintptr_t
+
 // These are the constants describing Node internal structures. Every constant
 // should use the format described above.  These constants are declared as
 // global integers so that they'll be present in the generated node binary. They
