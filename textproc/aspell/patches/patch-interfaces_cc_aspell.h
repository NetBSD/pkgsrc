$NetBSD: patch-interfaces_cc_aspell.h,v 1.1 2013/08/17 11:19:03 joerg Exp $

--- interfaces/cc/aspell.h.orig	2011-07-02 21:53:27.000000000 +0000
+++ interfaces/cc/aspell.h
@@ -236,7 +236,7 @@ void delete_aspell_can_have_error(struct
 
 /******************************** errors ********************************/
 
-
+#ifndef ASPELL_ERRORS__HPP
 extern const struct AspellErrorInfo * const aerror_other;
 extern const struct AspellErrorInfo * const aerror_operation_not_supported;
 extern const struct AspellErrorInfo * const   aerror_cant_copy;
@@ -322,7 +322,7 @@ extern const struct AspellErrorInfo * co
 extern const struct AspellErrorInfo * const   aerror_bad_magic;
 extern const struct AspellErrorInfo * const aerror_expression;
 extern const struct AspellErrorInfo * const   aerror_invalid_expression;
-
+#endif
 
 /******************************* speller *******************************/
 
