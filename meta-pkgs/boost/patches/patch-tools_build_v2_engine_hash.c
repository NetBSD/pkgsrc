# $NetBSD: patch-tools_build_v2_engine_hash.c,v 1.1 2013/01/16 16:27:23 martin Exp $
# fix alignement for sparc - time_t requires greater alignement than
# void*

--- tools/build/v2/engine/hash.c.orig	2012-04-26 05:35:55.000000000 +0200
+++ tools/build/v2/engine/hash.c	2013-01-16 16:13:21.000000000 +0100
@@ -32,10 +32,19 @@
 
 /* Header attached to all data items entered into a hash table. */
 
+#if defined(__sparc__) && defined(__NetBSD__)
+/* time_t is bigger than a pointer and needs natural alignement */
+#define	ARCH_ALIGNMENT	8
+#endif
+
 struct hashhdr
 {
     struct item  * next;
-};
+}
+#ifdef ARCH_ALIGNMENT
+ __attribute__((aligned(ARCH_ALIGNMENT)))
+#endif
+;
 
 typedef struct item
 {
