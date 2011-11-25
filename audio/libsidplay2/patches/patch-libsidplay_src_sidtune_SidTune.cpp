$NetBSD: patch-libsidplay_src_sidtune_SidTune.cpp,v 1.1 2011/11/25 21:30:19 joerg Exp $

--- libsidplay/src/sidtune/SidTune.cpp.orig	2011-11-25 19:32:28.000000000 +0000
+++ libsidplay/src/sidtune/SidTune.cpp
@@ -33,13 +33,6 @@
 #include <string.h>
 #include <limits.h>
 
-#if defined(HAVE_IOS_OPENMODE)
-    typedef std::ios::openmode openmode;
-#else
-    typedef int openmode;
-#endif
-
-
 const char* SidTune::txt_songNumberExceed = "SIDTUNE WARNING: Selected song number was too high";
 const char* SidTune::txt_empty = "SIDTUNE ERROR: No data to load";
 const char* SidTune::txt_unrecognizedFormat = "SIDTUNE ERROR: Could not determine file format";
@@ -283,7 +276,7 @@ bool SidTune::loadFile(const char* fileN
     uint_least32_t fileLen = 0;
 
     // This sucks big time
-    openmode createAtrr = std::ios::in;
+    std::ios::openmode createAtrr = std::ios::in;
 #ifdef HAVE_IOS_NOCREATE
     createAtrr |= std::ios::nocreate;
 #endif
@@ -952,7 +945,7 @@ bool SidTune::saveC64dataFile( const cha
     if ( status )
     {
         // Open binary output file stream.
-        openmode createAttr = std::ios::out;
+        std::ios::openmode createAttr = std::ios::out;
 #if defined(HAVE_IOS_BIN)
         createAttr |= std::ios::bin;
 #else
@@ -1002,7 +995,7 @@ bool SidTune::saveSIDfile( const char* f
     if ( status )
     {
         // Open ASCII output file stream.
-        openmode createAttr = std::ios::out;
+        std::ios::openmode createAttr = std::ios::out;
         if ( overWriteFlag )
             createAttr |= std::ios::trunc;
         else
@@ -1036,7 +1029,7 @@ bool SidTune::savePSIDfile( const char* 
     if ( status )
     {
         // Open binary output file stream.
-        openmode createAttr = std::ios::out;
+        std::ios::openmode createAttr = std::ios::out;
 #if defined(HAVE_IOS_BIN)
         createAttr |= std::ios::bin;
 #else
