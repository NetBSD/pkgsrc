$NetBSD: patch-src_uipp_base_IBMApplication.h,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/base/IBMApplication.h.orig	2012-04-16 23:33:18.000000000 +0000
+++ src/uipp/base/IBMApplication.h
@@ -77,7 +77,7 @@ class IBMApplication : public Applicatio
     //
     // Initialize the window system.
     //
-    virtual boolean initializeWindowSystem(unsigned int *argcp, char **argv);
+    virtual boolean initializeWindowSystem(int *argcp, char **argv);
 
     //
     // Protected member data:
@@ -88,7 +88,7 @@ class IBMApplication : public Applicatio
 
     HelpWin		*helpWindow;
 
-    boolean initialize(unsigned int* argcp, char** argv);
+    boolean initialize(int* argcp, char** argv);
 
     //
     // Load application specific action routines
