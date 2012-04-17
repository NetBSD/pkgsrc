$NetBSD: patch-src_uipp_tutor_TutorApplication.h,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/tutor/TutorApplication.h.orig	1999-05-10 15:46:30.000000000 +0000
+++ src/uipp/tutor/TutorApplication.h
@@ -69,8 +69,7 @@ class TutorApplication : public IBMAppli
     // Overrides the Application class version:
     //   Initializes Xt Intrinsics with option list (switches).
     //
-    virtual boolean initialize(unsigned int* argcp,
-			    char**        argv);
+    virtual boolean initialize(int* argcp, char** argv);
 
     //
     // Handle Xt Warnings (called by TutorApplication_XtWarningHandler, static, above)
