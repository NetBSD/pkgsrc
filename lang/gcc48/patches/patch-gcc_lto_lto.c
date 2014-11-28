$NetBSD: patch-gcc_lto_lto.c,v 1.2 2014/11/28 09:57:32 obache Exp $

--- gcc/lto/lto.c.orig	2013-02-07 18:01:40.000000000 +0000
+++ gcc/lto/lto.c
@@ -3102,6 +3102,14 @@ read_cgraph_and_symbols (unsigned nfiles
   all_file_decl_data = NULL;
 }
 
+#ifdef __OpenBSD__
+const char *
+fname_as_string(int pretty_p __attribute__((__unused__)))
+{
+	return NULL;
+}
+#endif
+
 
 /* Materialize all the bodies for all the nodes in the callgraph.  */
 
