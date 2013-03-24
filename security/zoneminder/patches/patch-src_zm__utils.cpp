$NetBSD: patch-src_zm__utils.cpp,v 1.1 2013/03/24 16:47:47 joerg Exp $

--- src/zm_utils.cpp.orig	2011-06-21 09:19:11.000000000 +0000
+++ src/zm_utils.cpp
@@ -38,21 +38,6 @@ const std::string stringtf( const char *
     return( tempString );
 }
 
-const std::string stringtf( const std::string &format, ... )
-{
-    va_list ap;
-    char tempBuffer[8192];
-    std::string tempString;
-
-    va_start(ap, format );
-    vsnprintf( tempBuffer, sizeof(tempBuffer), format.c_str() , ap );
-    va_end(ap);
-
-    tempString = tempBuffer;
-
-    return( tempString );
-}
-
 bool startsWith( const std::string &haystack, const std::string &needle )
 {
     return( haystack.substr( 0, needle.length() ) == needle );
