$NetBSD: patch-src_mp4.cpp,v 1.1 2020/12/20 13:07:58 nia Exp $

Fix building C applications.

Reverts the following commit:
https://github.com/TechSmith/mp4v2/commit/263719465a1c1fbe6d240b8d154da71003ce3230
https://github.com/TechSmith/mp4v2/issues/47

--- src/mp4.cpp.orig	2020-12-07 23:16:32.000000000 +0000
+++ src/mp4.cpp
@@ -87,7 +87,7 @@ const char* MP4GetFilename( MP4FileHandl
 
 ///////////////////////////////////////////////////////////////////////////////
 
-MP4FileHandle MP4Read( const char* fileName, ShouldParseAtomCallback cb/*=nullptr*/ )
+MP4FileHandle MP4Read( const char* fileName )
 {
     if (!fileName)
         return MP4_INVALID_FILE_HANDLE;
@@ -100,9 +100,6 @@ MP4FileHandle MP4Read( const char* fileN
     {
         ASSERT(pFile);
 
-        if ( cb != nullptr )
-           pFile->SetShouldParseAtomCallback( cb );
-
         pFile->Read( fileName, NULL );
         return (MP4FileHandle)pFile;
     }
@@ -149,6 +146,30 @@ MP4FileHandle MP4ReadProvider( const cha
 
 ///////////////////////////////////////////////////////////////////////////////
 
+void MP4SetShouldParseAtomCallback( MP4FileHandle hFile, ShouldParseAtomCallback cb )
+{
+   if (!MP4_IS_VALID_FILE_HANDLE(hFile))
+      return;
+   try
+   {
+      ASSERT(hFile);
+      MP4File& file = *static_cast<MP4File*>(hFile);
+      file.SetShouldParseAtomCallback( cb );
+   }
+   catch( Exception* x ) {
+      mp4v2::impl::log.errorf(*x);
+      delete x;
+   }
+   catch( ... ) {
+      mp4v2::impl::log.errorf("%s: unknown exception accessing MP4File "
+                               "filename", __FUNCTION__ );
+   }
+
+//   g_parseCallback = cb;
+}
+
+///////////////////////////////////////////////////////////////////////////////
+
     MP4FileHandle MP4Create (const char* fileName,
                              uint32_t  flags)
     {
