$NetBSD: patch-src_uipp_dxuilib_DXApplication.h,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/dxuilib/DXApplication.h.orig	2006-05-08 16:20:10.000000000 +0000
+++ src/uipp/dxuilib/DXApplication.h
@@ -372,8 +372,7 @@ class DXApplication : public IBMApplicat
     // Overrides the Application class version:
     //   Initializes Xt Intrinsics with option list (switches).
     //
-    virtual boolean initialize(unsigned int* argcp,
-			    char**        argv);
+    virtual boolean initialize(int* argcp, char** argv);
 
     //
     // Override of superclass handleEvents() function:
