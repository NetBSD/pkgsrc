$NetBSD: patch-util_mp4file.cpp,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- util/mp4file.cpp.orig	2021-04-13 11:48:31.000000000 +0000
+++ util/mp4file.cpp
@@ -43,7 +43,7 @@ public:
 
 protected:
     // delegates implementation
-    bool utility_option( int, bool& );
+    bool utility_option( unsigned int, bool& );
     bool utility_job( JobContext& );
 
 private:
@@ -185,7 +185,7 @@ FileUtility::utility_job( JobContext& jo
 ///////////////////////////////////////////////////////////////////////////////
 
 bool
-FileUtility::utility_option( int code, bool& handled )
+FileUtility::utility_option( unsigned int code, bool& handled )
 {
     handled = true;
 
