$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_parser_generator.cxx,v 1.2 2013/03/28 21:20:15 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/parser/generator.cxx.orig	2008-07-28 12:00:51.000000000 +0000
+++ xsd-3.2.0-2/xsd/cxx/parser/generator.cxx
@@ -539,7 +539,7 @@ namespace CXX
     {
       try
       {
-        Path fs_path (path, boost::filesystem::native);
+        Path fs_path (path);
         ifs.open (fs_path, std::ios_base::in | std::ios_base::binary);
 
         if (!ifs.is_open ())
@@ -623,7 +623,7 @@ namespace CXX
       {
         if (NarrowString name = ops.value<CLI::extern_xml_schema> ())
         {
-          if (file_path.native_file_string () != name)
+          if (file_path.string () != name)
             generate_xml_schema = false;
         }
       }
@@ -689,8 +689,8 @@ namespace CXX
 
         // String-based types.
         //
-        String char_type (ops.value<CLI::char_type> ());
-        String string_type;
+        WideString char_type (ops.value<CLI::char_type> ());
+        WideString string_type;
 
         if (char_type == L"char")
           string_type = L"::std::string";
@@ -699,13 +699,13 @@ namespace CXX
         else
           string_type = L"::std::basic_string< " + char_type + L" >";
 
-        String xns;
+        WideString xns;
         {
           Context ctx (std::wcerr, schema, ops, 0, 0, 0);
           xns = ctx.xs_ns_name ();
         }
 
-        String buffer (L"::std::auto_ptr< " + xns + L"::buffer >");
+        WideString buffer (L"::std::auto_ptr< " + xns + L"::buffer >");
         TypeMap::Namespace xsd ("http://www\\.w3\\.org/2001/XMLSchema");
 
         xsd.types_push_back ("string", string_type);
@@ -800,7 +800,7 @@ namespace CXX
 
       // Generate code.
       //
-      NarrowString name (file_path.leaf ());
+      NarrowString name (file_path.leaf ().c_str());
       NarrowString skel_suffix (ops.value <CLI::skel_file_suffix> ());
       NarrowString impl_suffix (ops.value <CLI::impl_file_suffix> ());
 
@@ -906,9 +906,9 @@ namespace CXX
         cxx_driver_name = cxx_driver_expr.merge (name);
       }
 
-      Path hxx_path (hxx_name, boost::filesystem::native);
-      Path ixx_path (ixx_name, boost::filesystem::native);
-      Path cxx_path (cxx_name, boost::filesystem::native);
+      Path hxx_path (hxx_name);
+      Path ixx_path (ixx_name);
+      Path cxx_path (cxx_name);
 
       Path hxx_impl_path;
       Path cxx_impl_path;
@@ -916,16 +916,16 @@ namespace CXX
 
       if (impl || driver)
       {
-        hxx_impl_path = Path (hxx_impl_name, boost::filesystem::native);
-        cxx_impl_path = Path (cxx_impl_name, boost::filesystem::native);
-        cxx_driver_path = Path (cxx_driver_name, boost::filesystem::native);
+        hxx_impl_path = Path (hxx_impl_name);
+        cxx_impl_path = Path (cxx_impl_name);
+        cxx_driver_path = Path (cxx_driver_name);
       }
 
       if (NarrowString dir  = ops.value<CLI::output_dir> ())
       {
         try
         {
-          Path path (dir, boost::filesystem::native);
+          Path path (dir);
 
           hxx_path = path / hxx_path;
           ixx_path = path / ixx_path;
@@ -978,7 +978,7 @@ namespace CXX
         }
 
         unlinks.add (hxx_impl_path);
-        file_list.push_back (hxx_impl_path.native_file_string ());
+        file_list.push_back (hxx_impl_path.string ());
 
         if (!ops.value<CLI::force_overwrite> ())
         {
@@ -1004,7 +1004,7 @@ namespace CXX
         }
 
         unlinks.add (cxx_impl_path);
-        file_list.push_back (cxx_impl_path.native_file_string ());
+        file_list.push_back (cxx_impl_path.string ());
       }
 
       if (driver)
@@ -1033,7 +1033,7 @@ namespace CXX
         }
 
         unlinks.add (cxx_driver_path);
-        file_list.push_back (cxx_driver_path.native_file_string ());
+        file_list.push_back (cxx_driver_path.string ());
       }
 
       // Open the skel files.
@@ -1049,7 +1049,7 @@ namespace CXX
       }
 
       unlinks.add (hxx_path);
-      file_list.push_back (hxx_path.native_file_string ());
+      file_list.push_back (hxx_path.string ());
 
       if (inline_)
       {
@@ -1062,7 +1062,7 @@ namespace CXX
         }
 
         unlinks.add (ixx_path);
-        file_list.push_back (ixx_path.native_file_string ());
+        file_list.push_back (ixx_path.string ());
       }
 
 
@@ -1077,7 +1077,7 @@ namespace CXX
         }
 
         unlinks.add (cxx_path);
-        file_list.push_back (cxx_path.native_file_string ());
+        file_list.push_back (cxx_path.string ());
       }
 
       // Print copyright and license.
@@ -1136,7 +1136,7 @@ namespace CXX
       NarrowString guard_prefix (ops.value<CLI::guard_prefix> ());
 
       if (!guard_prefix)
-        guard_prefix = file_path.branch_path ().native_directory_string ();
+        guard_prefix = file_path.branch_path ().string ();
 
       if (guard_prefix)
         guard_prefix += '_';
@@ -1148,7 +1148,7 @@ namespace CXX
 
         Indentation::Clip<Indentation::SLOC, WideChar> hxx_sloc (hxx);
 
-        String guard (guard_expr.merge (guard_prefix + hxx_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_name));
         guard = ctx.escape (guard); // Make it a C++ id.
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
@@ -1354,7 +1354,7 @@ namespace CXX
         Context ctx (hxx_impl, schema, ops,
                      &hxx_expr, &ixx_expr, &hxx_impl_expr);
 
-        String guard (guard_expr.merge (guard_prefix + hxx_impl_name));
+        WideString guard (guard_expr.merge (guard_prefix + hxx_impl_name));
         guard = ctx.escape (guard); // Make it a C++ id.
         std::transform (guard.begin (), guard.end(), guard.begin (), upcase);
 
