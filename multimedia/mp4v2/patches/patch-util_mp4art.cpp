$NetBSD: patch-util_mp4art.cpp,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- util/mp4art.cpp.orig	2021-04-13 11:47:19.000000000 +0000
+++ util/mp4art.cpp
@@ -48,7 +48,7 @@ public:
 
 protected:
     // delegates implementation
-    bool utility_option( int, bool& );
+    bool utility_option( unsigned int, bool& );
     bool utility_job( JobContext& );
 
 private:
@@ -372,7 +372,7 @@ ArtUtility::utility_job( JobContext& job
 ///////////////////////////////////////////////////////////////////////////////
 
 bool
-ArtUtility::utility_option( int code, bool& handled )
+ArtUtility::utility_option( unsigned int code, bool& handled )
 {
     handled = true;
 
