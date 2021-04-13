$NetBSD: patch-util_mp4chaps.cpp,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- util/mp4chaps.cpp.orig	2021-04-13 11:49:05.000000000 +0000
+++ util/mp4chaps.cpp
@@ -74,7 +74,7 @@ public:
 
 protected:
     // delegates implementation
-    bool utility_option( int, bool& );
+    bool utility_option( unsigned int, bool& );
     bool utility_job( JobContext& );
 
 private:
@@ -628,7 +628,7 @@ ChapterUtility::utility_job( JobContext&
  *  @see Utility::utility_option( int, bool& )
  */
 bool
-ChapterUtility::utility_option( int code, bool& handled )
+ChapterUtility::utility_option( unsigned int code, bool& handled )
 {
     handled = true;
 
