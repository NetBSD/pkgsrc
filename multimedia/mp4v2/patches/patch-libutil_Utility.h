$NetBSD: patch-libutil_Utility.h,v 1.1 2021/04/13 16:32:09 adam Exp $

Fix "cannot be narrowed to type 'int'" error.

--- libutil/Utility.h.orig	2021-04-13 11:52:53.000000000 +0000
+++ libutil/Utility.h
@@ -141,7 +141,7 @@ protected:
     bool dryrunAbort();
 
     // delegates
-    virtual bool utility_option( int, bool& ) = 0; //!< process command-line option
+    virtual bool utility_option( unsigned int, bool& ) = 0; //!< process command-line option
     virtual bool utility_job( JobContext& )   = 0; //!< process positional argument
 
 private:
