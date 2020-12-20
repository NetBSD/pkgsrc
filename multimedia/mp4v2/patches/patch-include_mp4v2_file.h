$NetBSD: patch-include_mp4v2_file.h,v 1.1 2020/12/20 13:07:58 nia Exp $

Fix building C applications.

Reverts the following commit:
https://github.com/TechSmith/mp4v2/commit/263719465a1c1fbe6d240b8d154da71003ce3230
https://github.com/TechSmith/mp4v2/issues/47

--- include/mp4v2/file.h.orig	2020-12-07 23:16:32.000000000 +0000
+++ include/mp4v2/file.h
@@ -328,12 +328,9 @@ bool MP4Optimize(
  *      the library.
  *      On error, #MP4_INVALID_FILE_HANDLE.
  */
-typedef bool( *ShouldParseAtomCallback )( uint32_t );
-
 MP4V2_EXPORT
 MP4FileHandle MP4Read(
-    const char* fileName,
-    ShouldParseAtomCallback cb = nullptr );
+    const char* fileName );
 
 /** Read an existing mp4 file.
  *
@@ -361,6 +358,13 @@ MP4FileHandle MP4ReadProvider(
     const char*            fileName,
     const MP4FileProvider* fileProvider DEFAULT(NULL) );
 
+typedef bool( *ShouldParseAtomCallback )( uint32_t );
+MP4V2_EXPORT
+void MP4SetShouldParseAtomCallback(
+   MP4FileHandle hFile,
+   ShouldParseAtomCallback f
+);
+
 /** @} ***********************************************************************/
 
 #endif /* MP4V2_FILE_H */
