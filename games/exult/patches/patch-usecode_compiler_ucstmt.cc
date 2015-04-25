$NetBSD: patch-usecode_compiler_ucstmt.cc,v 1.1 2015/04/25 00:56:04 joerg Exp $

Key function must not be inline, otherwise the vtable is not created.

--- usecode/compiler/ucstmt.cc.orig	2015-04-25 00:38:04.000000000 +0000
+++ usecode/compiler/ucstmt.cc
@@ -808,7 +808,7 @@ void Uc_converse_statement::gen
  *	Delete.
  */
 
-inline Uc_switch_expression_case_statement::~Uc_switch_expression_case_statement
+Uc_switch_expression_case_statement::~Uc_switch_expression_case_statement
 	(
 	)
 	{
