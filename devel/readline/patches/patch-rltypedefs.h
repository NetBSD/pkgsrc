$NetBSD: patch-rltypedefs.h,v 1.1 2014/08/11 21:29:00 markd Exp $

Readline-6.3 Official Patch 5

There are still applications using the deprecated Function/VFunction/etc.
typedefs in rltypedefs.h.  This patch restores the typedefs, but attempts
to mark them as deprecated using gcc/clang attributes.  Thanks to Max Horn
for the suggestion.

--- rltypedefs.h.orig	2011-03-26 18:53:31.000000000 +0000
+++ rltypedefs.h
@@ -26,6 +26,25 @@
 extern "C" {
 #endif
 
+/* Old-style, attempt to mark as deprecated in some way people will notice. */
+
+#if !defined (_FUNCTION_DEF)
+#  define _FUNCTION_DEF
+
+#if defined(__GNUC__) || defined(__clang__)
+typedef int Function () __attribute__ ((deprecated));
+typedef void VFunction () __attribute__ ((deprecated));
+typedef char *CPFunction () __attribute__ ((deprecated));
+typedef char **CPPFunction () __attribute__ ((deprecated));
+#else
+typedef int Function ();
+typedef void VFunction ();
+typedef char *CPFunction ();
+typedef char **CPPFunction ();
+#endif
+
+#endif /* _FUNCTION_DEF */
+
 /* New style. */
 
 #if !defined (_RL_FUNCTION_TYPEDEF)
