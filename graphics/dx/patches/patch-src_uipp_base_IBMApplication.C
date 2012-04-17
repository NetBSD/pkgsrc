$NetBSD: patch-src_uipp_base_IBMApplication.C,v 1.1 2012/04/17 17:44:02 joerg Exp $

--- src/uipp/base/IBMApplication.C.orig	2012-04-16 23:33:21.000000000 +0000
+++ src/uipp/base/IBMApplication.C
@@ -349,7 +349,7 @@ int status;
 }
 
 
-boolean IBMApplication::initializeWindowSystem(unsigned int *argcp, char **argv)
+boolean IBMApplication::initializeWindowSystem(int *argcp, char **argv)
 {
 
     if (!this->Application::initializeWindowSystem(argcp, argv))
@@ -375,8 +375,7 @@ boolean IBMApplication::initializeWindow
     return TRUE;
 }
 
-boolean IBMApplication::initialize(unsigned int* argcp,
-				   char**        argv)
+boolean IBMApplication::initialize(int* argcp, char** argv)
 {
     if (!this->Application::initialize(argcp,argv))
         return FALSE;
