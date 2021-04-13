$NetBSD: patch-util_mp4subtitle.cpp,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- util/mp4subtitle.cpp.orig	2021-04-13 11:48:49.000000000 +0000
+++ util/mp4subtitle.cpp
@@ -43,7 +43,7 @@ public:
 
 protected:
     // delegates implementation
-    bool utility_option( int, bool& );
+    bool utility_option( unsigned int, bool& );
     bool utility_job( JobContext& );
 
 private:
@@ -160,7 +160,7 @@ SubtitleUtility::utility_job( JobContext
 ///////////////////////////////////////////////////////////////////////////////
 
 bool
-SubtitleUtility::utility_option( int code, bool& handled )
+SubtitleUtility::utility_option( unsigned int code, bool& handled )
 {
     handled = true;
 
