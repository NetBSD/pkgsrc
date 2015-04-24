$NetBSD: patch-src_zm__utils.h,v 1.1.18.1 2015/04/24 16:07:10 hiramatsu Exp $

--- src/zm_utils.h.orig	2015-04-01 17:20:39.840273017 +1300
+++ src/zm_utils.h	2015-04-01 17:28:57.376293647 +1300
@@ -33,7 +33,6 @@
 std::string replaceAll(std::string str, std::string from, std::string to);
 
 const std::string stringtf( const char *format, ... );
-const std::string stringtf( const std::string &format, ... );
 
 bool startsWith( const std::string &haystack, const std::string &needle );
 StringVector split( const std::string &string, const std::string chars, int limit=0 );
