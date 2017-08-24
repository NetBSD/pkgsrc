$NetBSD: patch-boost_property__tree_detail_xml__parser__read__rapidxml.hpp,v 1.1 2017/08/24 19:31:32 adam Exp $

--- boost/property_tree/detail/xml_parser_read_rapidxml.hpp.orig	2017-08-19 16:49:45.000000000 +0000
+++ boost/property_tree/detail/xml_parser_read_rapidxml.hpp
@@ -103,13 +103,13 @@ namespace boost { namespace property_tre
 
         try {
             // Parse using appropriate flags
-            const int f_tws = parse_normalize_whitespace
-                            | parse_trim_whitespace;
+            const int f_tws = (parse_normalize_whitespace
+                            | parse_trim_whitespace);
             const int f_c = parse_comment_nodes;
             // Some compilers don't like the bitwise or in the template arg.
-            const int f_tws_c = parse_normalize_whitespace
+            const int f_tws_c = (parse_normalize_whitespace
                               | parse_trim_whitespace
-                              | parse_comment_nodes;
+                              | parse_comment_nodes);
             xml_document<Ch> doc;
             if (flags & no_comments) {
                 if (flags & trim_whitespace)
