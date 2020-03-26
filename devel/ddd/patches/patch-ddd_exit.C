$NetBSD: patch-ddd_exit.C,v 1.1 2020/03/26 21:49:22 joerg Exp $

--- ddd/exit.C.orig	2020-03-26 12:39:56.118867681 +0000
+++ ddd/exit.C
@@ -769,6 +769,9 @@ static void PostXtErrorCB(XtPointer clie
 
 static XtAppContext xt_error_app_context = 0;
 
+#ifdef _X_NORETURN
+_X_NORETURN
+#endif
 static void ddd_xt_error(String message = 0)
 {
     ddd_has_crashed = true;
