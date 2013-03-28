$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_tree_generator.cxx,v 1.1 2013/03/28 21:20:15 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/tree/generator.cxx.orig	2013-03-28 16:28:31.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/tree/generator.cxx
@@ -717,7 +717,7 @@ namespace CXX
     {
       try
       {
-        Path fs_path (path, boost::filesystem::native);
+        Path fs_path (path);
         ifs.open (fs_path, std::ios_base::in | std::ios_base::binary);
 
         if (!ifs.is_open ())
@@ -871,7 +871,7 @@ namespace CXX
       {
         if (NarrowString name = ops.value<CLI::extern_xml_schema> ())
         {
-          if (file_path.native_file_string () != name)
+          if (file_path.string () != name)
             generate_xml_schema = false;
         }
       }
@@ -886,7 +886,7 @@ namespace CXX
 
       // Generate code.
       //
-      NarrowString name (file_path.leaf ());
+      NarrowString name (file_path.leaf ().string());
 
       NarrowString hxx_suffix (ops.value <CLI::hxx_suffix> ());
       NarrowString ixx_suffix (ops.value <CLI::ixx_suffix> ());
@@ -945,9 +945,9 @@ namespace CXX
       NarrowString ixx_name (inline_ ? ixx_expr.merge (name) : NarrowString ());
       NarrowString fwd_name (forward ? fwd_expr.merge (name) : NarrowString ());
 
-      Path hxx_path (hxx_name, boost::filesystem::native);
-      Path ixx_path (ixx_name, boost::filesystem::native);
-      Path fwd_path (fwd_name, boost::filesystem::native);
+      Path hxx_path (hxx_name);
+      Path ixx_path (ixx_name);
+      Path fwd_path (fwd_name);
       Paths cxx_paths;
 
       if (source)
@@ -973,19 +973,19 @@ namespace CXX
             }
 
             cxx_paths.push_back (
-              Path (cxx_expr.merge (part_name), boost::filesystem::native));
+              Path (cxx_expr.merge (part_name)));
           }
         }
         else
           cxx_paths.push_back (
-            Path (cxx_expr.merge (name), boost::filesystem::native));
+            Path (cxx_expr.merge (name)));
       }
 
       if (NarrowString dir  = ops.value<CLI::output_dir> ())
       {
         try
         {
-          Path path (dir, boost::filesystem::native);
+          Path path (dir);
 
           hxx_path = path / hxx_path;
           ixx_path = path / ixx_path;
@@ -1023,7 +1023,7 @@ namespace CXX
         }
 
         unlinks.add (fwd_path);
-        file_list.push_back (fwd_path.native_file_string ());
+        file_list.push_back (fwd_path.string ());
       }
 
 
@@ -1036,7 +1036,7 @@ namespace CXX
       }
 
       unlinks.add (hxx_path);
-      file_list.push_back (hxx_path.native_file_string ());
+      file_list.push_back (hxx_path.string ());
 
 
       // IXX
@@ -1052,7 +1052,7 @@ namespace CXX
         }
 
         unlinks.add (ixx_path);
-        file_list.push_back (ixx_path.native_file_string ());
+        file_list.push_back (ixx_path.string ());
       }
 
 
@@ -1073,7 +1073,7 @@ namespace CXX
           }
 
           unlinks.add (*i);
-          file_list.push_back (i->native_file_string ());
+          file_list.push_back (i->string ());
           cxx.push_back (s);
         }
       }
@@ -1145,7 +1145,7 @@ namespace CXX
       NarrowString guard_prefix (ops.value<CLI::guard_prefix> ());
 
       if (!guard_prefix)
-        guard_prefix = file_path.branch_path ().native_directory_string ();
+        guard_prefix = file_path.branch_path ().string ();
 
       if (guard_prefix)
         guard_prefix += '_';
@@ -1161,7 +1161,7 @@ namespace CXX
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + fwd_name));
+        WideString guard (guard_expr.merge (guard_prefix + fwd_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
@@ -1269,7 +1269,7 @@ namespace CXX
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + hxx_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
@@ -1415,7 +1415,7 @@ namespace CXX
 
         // Guard
         //
-        String guard (guard_expr.merge (guard_prefix + ixx_name));
+        WideString guard (guard_expr.merge (guard_prefix + ixx_name));
         guard = ctx.escape (guard); // make a c++ id
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
