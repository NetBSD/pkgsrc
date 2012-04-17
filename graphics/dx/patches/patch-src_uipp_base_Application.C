$NetBSD: patch-src_uipp_base_Application.C,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/base/Application.C.orig	2012-04-16 23:44:12.000000000 +0000
+++ src/uipp/base/Application.C
@@ -136,7 +136,7 @@ void Application::installDefaultResource
     //this->setDefaultResources(baseWidget, Application::DefaultResources);
 }
 
-boolean Application::initializeWindowSystem(unsigned int *argcp, char **argv) 
+boolean Application::initializeWindowSystem(int *argcp, char **argv) 
 {
 
     //
@@ -148,11 +148,7 @@ boolean Application::initializeWindowSys
 	     this->applicationClass,	// application class name
 	     NULL,			// command line options table
 	     0,				// number of entries in options table
-#if XtSpecificationRelease > 4
-	     (int*)argcp,
-#else
 	     argcp,
-#endif
 	     argv,			 // "argv" command line arguments
 #if XtSpecificationRelease > 4
 	     NULL,			 // fallback resource list
@@ -235,7 +231,7 @@ boolean Application::initializeWindowSys
     return TRUE;
 }
 
-void Application::parseCommand(unsigned int* argcp, char** argv,
+void Application::parseCommand(int* argcp, char** argv,
                                XrmOptionDescList optlist, int optlistsize)
 {
     char res_file[256];
@@ -280,7 +276,7 @@ void Application::parseCommand(unsigned 
     //
 }
 
-boolean Application::initialize(unsigned int* argcp, char** argv)
+boolean Application::initialize(int* argcp, char** argv)
 {
     //
     // Initialize the window system if not done already.
