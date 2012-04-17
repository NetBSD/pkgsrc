$NetBSD: patch-src_uipp_mb_MBApplication.C,v 1.1 2012/04/17 17:44:03 joerg Exp $

--- src/uipp/mb/MBApplication.C.orig	2006-05-08 16:20:13.000000000 +0000
+++ src/uipp/mb/MBApplication.C
@@ -117,8 +117,7 @@ InitializeSignals(void)
 #endif       
 }            
 
-boolean MBApplication::initialize(unsigned int* argcp,
-			       char**        argv)
+boolean MBApplication::initialize(int* argcp, char** argv)
 {
     ASSERT(argcp);
     ASSERT(argv);
