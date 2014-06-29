$NetBSD: patch-vslib_vstring.cpp,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vslib/vstring.cpp~	2002-05-24 16:55:36.000000000 +0000
+++ vslib/vstring.cpp
@@ -412,7 +412,7 @@
   {
     int sl = strlen( target );
     if (startpos >= sl) return -1;
-    char* pc = strchr( target + startpos, s );
+    const char* pc = strchr( target + startpos, s );
     if( ! pc )
       return -1;
     return  pc - target;
@@ -420,7 +420,7 @@
 
   int str_rfind( const char* target, const char c ) // returns last zero-based position of char, or -1 if not found
   {
-    char* pc = strrchr( target, c );
+    const char* pc = strrchr( target, c );
     if( ! pc )
       return -1;
     return  pc - target;
@@ -430,7 +430,7 @@
   {
     int sl = strlen( target );
     if (startpos >= sl) return -1;
-    char* pc = strstr( target + startpos, s );
+    const char* pc = strstr( target + startpos, s );
     if( ! pc )
       return -1;
     return  pc - target;
@@ -707,7 +707,7 @@
     int sl = strlen( target );
     for( z = 0; z < sl; z++ )
       {
-      char *pc = strchr( from, target[z] );
+      const char *pc = strchr( from, target[z] );
       if (pc) target[z] = to[ pc - from ];
       }
     return target;
