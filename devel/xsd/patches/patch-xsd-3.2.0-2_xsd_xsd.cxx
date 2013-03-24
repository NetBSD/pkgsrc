$NetBSD: patch-xsd-3.2.0-2_xsd_xsd.cxx,v 1.1 2013/03/24 16:58:29 joerg Exp $

--- xsd-3.2.0-2/xsd/xsd.cxx.orig	2013-03-23 19:56:31.000000000 +0000
+++ xsd-3.2.0-2/xsd/xsd.cxx
@@ -566,7 +566,7 @@ main (Int argc, Char* argv[])
 
         try
         {
-          tu = SemanticGraph::Path (args[i], boost::filesystem::native);
+          tu = SemanticGraph::Path (args[i]);
         }
         catch (SemanticGraph::InvalidPath const&)
         {
@@ -604,7 +604,7 @@ main (Int argc, Char* argv[])
               if (NarrowString name =
                   tree_ops->value<CXX::Tree::CLI::extern_xml_schema> ())
               {
-                if (tu.native_file_string () != name)
+                if (tu.string () != name)
                   gen_xml_schema = false;
               }
             }
@@ -619,7 +619,7 @@ main (Int argc, Char* argv[])
               if (NarrowString name =
                   parser_ops->value<CXX::Parser::CLI::extern_xml_schema> ())
               {
-                if (tu.native_file_string () != name)
+                if (tu.string () != name)
                   gen_xml_schema = false;
               }
             }
@@ -730,7 +730,7 @@ main (Int argc, Char* argv[])
         try
         {
           paths.push_back (
-            SemanticGraph::Path (args[i], boost::filesystem::native));
+            SemanticGraph::Path (args[i]));
         }
         catch (SemanticGraph::InvalidPath const&)
         {
