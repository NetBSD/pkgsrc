$NetBSD: patch-vfu_vfusys.cpp,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vfu/vfusys.cpp~	2002-04-26 07:24:21.000000000 +0000
+++ vfu/vfusys.cpp
@@ -138,8 +138,8 @@ int  vfu_edit_attr( mode_str_t mod_str, 
     for ( int z = 0; z < 16; z++ ) mode_i[z] = 2;
     }
 
-  char* AONOFF1[] = { "YES", " - ", " ? ", NULL };
-  char* AONOFF2[] = { "YES", " - ", NULL };
+  const char* AONOFF1[] = { "YES", " - ", " ? ", NULL };
+  const char* AONOFF2[] = { "YES", " - ", NULL };
   #define AONOFF  ( allow_masking ? AONOFF1 : AONOFF2 )
   ToggleEntry mode_toggles[] =
   {
