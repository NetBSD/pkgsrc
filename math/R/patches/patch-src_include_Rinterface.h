$NetBSD: patch-src_include_Rinterface.h,v 1.1 2015/06/29 21:35:04 markd Exp $

Fix symbol visibility.

--- src/include/Rinterface.h.orig	2015-03-18 23:02:16.000000000 +0000
+++ src/include/Rinterface.h
@@ -90,7 +90,7 @@ void R_setStartTime(void);
 void fpu_setup(Rboolean);
 
 /* in unix/system.c */
-int R_running_as_main_program; 
+extern int R_running_as_main_program; 
 
 #ifdef CSTACK_DEFNS
 /* duplicating Defn.h */
