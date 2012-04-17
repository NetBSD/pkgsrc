$NetBSD: patch-src_uipp_base_Application.h,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/base/Application.h.orig	2005-11-09 18:26:29.000000000 +0000
+++ src/uipp/base/Application.h
@@ -49,8 +49,7 @@ class Application : public UIComponent, 
     //
     // The main program needs to access protected member functions.
     //
-    friend int main(unsigned int argc,
-		     char**       argv);
+    friend int main(int argc, char**argv);
 
 
     //
@@ -71,9 +70,9 @@ class Application : public UIComponent, 
     //
     // Initialize the window system.
     //
-    virtual boolean initializeWindowSystem(unsigned int *argcp, char **argv);
+    virtual boolean initializeWindowSystem(int *argcp, char **argv);
 
-    virtual void parseCommand(unsigned int* argcp, char** argv,
+    virtual void parseCommand(int* argcp, char** argv,
 			       XrmOptionDescList optlist, int optlistsize);
 
     //
@@ -145,7 +144,7 @@ class Application : public UIComponent, 
     // Initializes any Application specfic state.  This routine should 
     // be called by main() or subclasses only.
     //
-    virtual boolean initialize(unsigned int* argcp, char** argv);
+    virtual boolean initialize(int* argcp, char** argv);
 
     //
     // Allow others to access our event processing mechanism
