$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_tree_elements.cxx,v 1.1 2013/03/28 21:20:15 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/tree/elements.cxx.orig	2013-03-28 16:25:23.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/tree/elements.cxx
@@ -1282,7 +1282,7 @@ namespace CXX
       }
       catch (SemanticGraph::InvalidPath const&)
       {
-        path_str = path.native_file_string ();
+        path_str = path.string ();
       }
 
       String inc_path;
