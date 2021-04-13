$NetBSD: patch-util_mp4track.cpp,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- util/mp4track.cpp.orig	2021-04-13 11:49:26.000000000 +0000
+++ util/mp4track.cpp
@@ -78,7 +78,7 @@ public:
 
 protected:
     // delegates implementation
-    bool utility_option( int, bool& );
+    bool utility_option( unsigned int, bool& );
     bool utility_job( JobContext& );
 
 private:
@@ -784,7 +784,7 @@ TrackUtility::utility_job( JobContext& j
 ///////////////////////////////////////////////////////////////////////////////
 
 bool
-TrackUtility::utility_option( int code, bool& handled )
+TrackUtility::utility_option( unsigned int code, bool& handled )
 {
     handled = true;
 
