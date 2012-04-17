$NetBSD: patch-src_uipp_prompter_GARApplication.h,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/prompter/GARApplication.h.orig	2003-09-20 05:33:21.000000000 +0000
+++ src/uipp/prompter/GARApplication.h
@@ -129,8 +129,7 @@ class GARApplication : public IBMApplica
     // Overrides the Application class version:
     //   Initializes Xt Intrinsics with option list (switches).
     //
-    virtual boolean initialize(unsigned int* argcp,
-			    char**        argv);
+    virtual boolean initialize(int* argcp, char** argv);
 
     CommandScope       *commandScope;   // command scope
 
