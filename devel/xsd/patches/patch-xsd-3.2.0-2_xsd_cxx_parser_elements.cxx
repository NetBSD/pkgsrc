$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_parser_elements.cxx,v 1.1 2013/03/24 16:58:29 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/parser/elements.cxx.orig	2013-03-23 19:59:56.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/parser/elements.cxx
@@ -229,15 +229,7 @@ namespace CXX
       // Try to use the portable representation of the path. If that
       // fails, fall back to the native representation.
       //
-      NarrowString path_str;
-      try
-      {
-        path_str = path.string ();
-      }
-      catch (SemanticGraph::InvalidPath const&)
-      {
-        path_str = path.native_file_string ();
-      }
+      NarrowString path_str(path.string());
 
       String inc_path;
 
