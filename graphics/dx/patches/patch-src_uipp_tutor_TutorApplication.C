$NetBSD: patch-src_uipp_tutor_TutorApplication.C,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/tutor/TutorApplication.C.orig	2006-05-08 16:20:14.000000000 +0000
+++ src/uipp/tutor/TutorApplication.C
@@ -196,8 +196,7 @@ InitializeSignals(void)
 #endif       
 }            
 
-boolean TutorApplication::initialize(unsigned int* argcp,
-			       char**        argv)
+boolean TutorApplication::initialize(int* argcp, char** argv)
 {
     ASSERT(argcp);
     ASSERT(argv);
