$NetBSD: patch-src_zm__utils.cpp,v 1.3 2022/09/27 01:20:39 gdt Exp $

\todo Explain

--- src/zm_utils.cpp.orig	2019-02-22 15:38:47.000000000 +0000
+++ src/zm_utils.cpp
@@ -76,21 +76,6 @@ const std::string stringtf( const char *
   return( tempString );
 }
 
-const std::string stringtf( const std::string &format, ... )
-{
-  va_list ap;
-  char tempBuffer[8192];
-  std::string tempString;
-
-  va_start(ap, format );
-  vsnprintf( tempBuffer, sizeof(tempBuffer), format.c_str() , ap );
-  va_end(ap);
-
-  tempString = tempBuffer;
-
-  return( tempString );
-}
-
 bool startsWith( const std::string &haystack, const std::string &needle )
 {
   return( haystack.substr( 0, needle.length() ) == needle );
