$NetBSD: patch-src_zm__utils.h,v 1.1 2013/03/24 16:47:47 joerg Exp $

--- src/zm_utils.h.orig	2009-06-02 07:59:26.000000000 +0000
+++ src/zm_utils.h
@@ -26,7 +26,6 @@
 typedef std::vector<std::string> StringVector;
 
 const std::string stringtf( const char *format, ... );
-const std::string stringtf( const std::string &format, ... );
 
 bool startsWith( const std::string &haystack, const std::string &needle );
 StringVector split( const std::string &string, const std::string chars, int limit=0 );
