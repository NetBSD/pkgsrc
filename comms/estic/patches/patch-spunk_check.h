$NetBSD: patch-spunk_check.h,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/check.h.orig	1996-11-07 18:06:46.000000000 +0000
+++ spunk/check.h
@@ -38,9 +38,6 @@ extern const char* _MsgCheckFailed;     
 
 
 extern
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char* Msg, const char* Cond, int Code,
                             const char* File, int Line);
 // Function pointer that is called from Check if the condition code is true.
