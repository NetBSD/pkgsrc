$NetBSD: patch-source_expr2.c,v 1.1 2024/03/16 13:11:55 nia Exp $

Fix build with Clang > 13.

via Fedora Linux, but MacPorts has the same patch.

--- source/expr2.c.orig	2008-02-25 09:49:14.000000000 +0000
+++ source/expr2.c
@@ -1192,7 +1192,7 @@ int	lexerr (expr_info *c, char *format, 
  * case 'operand' is set to 1.  When an operand is lexed, then the next token
  * is expected to be a binary operator, so 'operand' is set to 0. 
  */
-__inline int	check_implied_arg (expr_info *c)
+__inline static int	check_implied_arg (expr_info *c)
 {
 	if (c->operand == 2)
 	{
@@ -1205,7 +1205,7 @@ __inline int	check_implied_arg (expr_inf
 	return c->operand;
 }
 
-__inline TOKEN 	operator (expr_info *c, char *x, int y, TOKEN z)
+__inline static TOKEN 	operator (expr_info *c, char *x, int y, TOKEN z)
 {
 	check_implied_arg(c);
 	if (c->operand)
@@ -1216,7 +1216,7 @@ __inline TOKEN 	operator (expr_info *c, 
 	return z;
 }
 
-__inline TOKEN 	unary (expr_info *c, char *x, int y, TOKEN z)
+__inline static TOKEN 	unary (expr_info *c, char *x, int y, TOKEN z)
 {
 	if (!c->operand)
 		return lexerr(c, "An operator (%s) was found where "
