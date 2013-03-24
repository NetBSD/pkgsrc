$NetBSD: patch-libxsd-frontend-1.15.0_xsd-frontend_parser.cxx,v 1.1 2013/03/24 16:58:28 joerg Exp $

--- libxsd-frontend-1.15.0/xsd-frontend/parser.cxx.orig	2013-03-23 19:50:39.000000000 +0000
+++ libxsd-frontend-1.15.0/xsd-frontend/parser.cxx
@@ -1126,7 +1126,7 @@ namespace XSDFrontend
     operator () (SemanticGraph::Path const& x,
                  SemanticGraph::Path const& y) const
     {
-        return x.native_file_string () < y.native_file_string ();
+        return x.string () < y.string ();
     }
   };
 
@@ -1446,8 +1446,8 @@ namespace XSDFrontend
       friend Boolean
       operator< (SchemaId const& x, SchemaId const& y)
       {
-        return x.path_.native_file_string () < y.path_.native_file_string ()
-          || (x.path_.native_file_string () == y.path_.native_file_string ()
+        return x.path_.string () < y.path_.string ()
+          || (x.path_.string () == y.path_.string ()
               && x.ns_ < y.ns_);
       }
 
@@ -2029,7 +2029,7 @@ namespace XSDFrontend
       {
         // Retry as a native path.
         //
-        path = Path (loc, boost::filesystem::native);
+        path = Path (loc);
       }
 
       if (path.is_complete ())
@@ -2129,7 +2129,7 @@ namespace XSDFrontend
       {
         // Retry as a native path.
         //
-        path = Path (loc, boost::filesystem::native);
+        path = Path (loc);
       }
 
       if (path.is_complete ())
@@ -4121,8 +4121,7 @@ namespace XSDFrontend
 
 
       XSDFrontend::SemanticGraph::Path abs_path (
-        XML::transcode_to_narrow (e.getLocation ()->getURI ()),
-        boost::filesystem::native);
+        XML::transcode_to_narrow (e.getLocation ()->getURI ()));
 
       XSDFrontend::SemanticGraph::Path rel_path (ctx_.file (abs_path));
 
@@ -4176,7 +4175,7 @@ namespace XSDFrontend
           ctx_ (ctx)
     {
       setSystemId (XML::XMLChString (
-                     String (abs_.native_file_string ())).c_str ());
+                     String (abs_.string())).c_str ());
     }
 
     virtual Xerces::BinInputStream*
@@ -4249,8 +4248,7 @@ namespace XSDFrontend
 
       // base_uri should be a valid path by now.
       //
-      Path base (XML::transcode_to_narrow (base_uri),
-                 boost::filesystem::native);
+      Path base (XML::transcode_to_narrow (base_uri));
 
       if (prv_id == 0)
       {
@@ -4274,18 +4272,7 @@ namespace XSDFrontend
 
       try
       {
-        Path path;
-
-        try
-        {
-          path = Path (path_str);
-        }
-        catch (InvalidPath const&)
-        {
-          // Retry as a native path.
-          //
-          path = Path (path_str, boost::filesystem::native);
-        }
+        Path path(path_str);
 
         Path base_dir (base.branch_path ());
 
@@ -4307,9 +4294,9 @@ namespace XSDFrontend
 
         using namespace Xerces;
 
-        InputSource* is (
+        InputSource* is =
           new (XMLPlatformUtils::fgMemoryManager)
-          InputSource (abs_path, rel_path, base, ctx_));
+          InputSource (abs_path, rel_path, base, ctx_);
 
         // Note that I can't use XMLPlatformUtils::fgMemoryManager here
         // since Wrapper4InputSource is-not-an XMemory.
