$NetBSD: patch-data_glr.c,v 1.1 2015/01/16 19:34:44 rumko Exp $

Fixes "error: an attribute list cannot appear here" on fbsd
under clang

--- data/glr.c.orig	2013-11-14 15:01:22.000000000 +0000
+++ data/glr.c
@@ -669,7 +669,7 @@ struct yyGLRStack {
 static void yyexpandGLRStack (yyGLRStack* yystackp);
 #endif
 
-static _Noreturn void
+_Noreturn static void
 yyFail (yyGLRStack* yystackp]b4_pure_formals[, const char* yymsg)
 {
   if (yymsg != YY_NULLPTR)
@@ -677,7 +677,7 @@ yyFail (yyGLRStack* yystackp]b4_pure_for
   YYLONGJMP (yystackp->yyexception_buffer, 1);
 }
 
-static _Noreturn void
+_Noreturn static void
 yyMemoryExhausted (yyGLRStack* yystackp)
 {
   YYLONGJMP (yystackp->yyexception_buffer, 2);
