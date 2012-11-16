$NetBSD: patch-spunk_check.cc,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/check.cc.orig	1996-11-07 18:06:46.000000000 +0000
+++ spunk/check.cc
@@ -50,9 +50,6 @@ static void _CheckFailed (const char* Ms
 
 
 // The fail vector
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char*, const char* Cond,
                      int Code, const char* File, int Line) = _CheckFailed;
 
