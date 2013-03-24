$NetBSD: patch-xsd-3.2.0-2_xsd_cxx_parser_generator.cxx,v 1.1 2013/03/24 16:58:29 joerg Exp $

--- xsd-3.2.0-2/xsd/cxx/parser/generator.cxx.orig	2013-03-23 20:02:16.000000000 +0000
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
@@ -692,12 +692,12 @@ namespace CXX
         String char_type (ops.value<CLI::char_type> ());
         String string_type;
 
-        if (char_type == L"char")
-          string_type = L"::std::string";
-        else if (char_type == L"wchar_t")
-          string_type = L"::std::wstring";
+        if (char_type == "char")
+          string_type = "::std::string";
+        else if (char_type == "wchar_t")
+          string_type = "::std::wstring";
         else
-          string_type = L"::std::basic_string< " + char_type + L" >";
+          string_type = "::std::basic_string< " + char_type + " >";
 
         String xns;
         {
@@ -705,7 +705,7 @@ namespace CXX
           xns = ctx.xs_ns_name ();
         }
 
-        String buffer (L"::std::auto_ptr< " + xns + L"::buffer >");
+        String buffer ("::std::auto_ptr< " + xns + "::buffer >");
         TypeMap::Namespace xsd ("http://www\\.w3\\.org/2001/XMLSchema");
 
         xsd.types_push_back ("string", string_type);
@@ -713,29 +713,29 @@ namespace CXX
         xsd.types_push_back ("token", string_type);
         xsd.types_push_back ("Name", string_type);
         xsd.types_push_back ("NMTOKEN", string_type);
-        xsd.types_push_back ("NMTOKENS", xns + L"::string_sequence");
+        xsd.types_push_back ("NMTOKENS", xns + "::string_sequence");
         xsd.types_push_back ("NCName", string_type);
 
         xsd.types_push_back ("ID", string_type);
         xsd.types_push_back ("IDREF", string_type);
-        xsd.types_push_back ("IDREFS", xns + L"::string_sequence");
+        xsd.types_push_back ("IDREFS", xns + "::string_sequence");
 
         xsd.types_push_back ("language", string_type);
         xsd.types_push_back ("anyURI", string_type);
-        xsd.types_push_back ("QName", xns + L"::qname");
+        xsd.types_push_back ("QName", xns + "::qname");
 
         xsd.types_push_back ("base64Binary", buffer, buffer);
         xsd.types_push_back ("hexBinary", buffer, buffer);
 
-        xsd.types_push_back ("gDay", xns + L"::gday");
-        xsd.types_push_back ("gMonth", xns + L"::gmonth");
-        xsd.types_push_back ("gYear", xns + L"::gyear");
-        xsd.types_push_back ("gMonthDay", xns + L"::gmonth_day");
-        xsd.types_push_back ("gYearMonth", xns + L"::gyear_month");
-        xsd.types_push_back ("date", xns + L"::date");
-        xsd.types_push_back ("time", xns + L"::time");
-        xsd.types_push_back ("dateTime", xns + L"::date_time");
-        xsd.types_push_back ("duration", xns + L"::duration");
+        xsd.types_push_back ("gDay", xns + "::gday");
+        xsd.types_push_back ("gMonth", xns + "::gmonth");
+        xsd.types_push_back ("gYear", xns + "::gyear");
+        xsd.types_push_back ("gMonthDay", xns + "::gmonth_day");
+        xsd.types_push_back ("gYearMonth", xns + "::gyear_month");
+        xsd.types_push_back ("date", xns + "::date");
+        xsd.types_push_back ("time", xns + "::time");
+        xsd.types_push_back ("dateTime", xns + "::date_time");
+        xsd.types_push_back ("duration", xns + "::duration");
 
         // Fundamental C++ types.
         //
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
