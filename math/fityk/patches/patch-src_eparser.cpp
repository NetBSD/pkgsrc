$NetBSD: patch-src_eparser.cpp,v 1.1 2013/04/30 22:25:40 joerg Exp $

--- src/eparser.cpp.orig	2013-04-30 20:10:11.000000000 +0000
+++ src/eparser.cpp
@@ -139,7 +139,7 @@ int get_function_narg(int op)
     }
 }
 
-bool is_function(int op)
+bool my_is_function(int op)
 {
     return (bool) get_function_narg(op);
 }
@@ -812,7 +812,7 @@ void ExpressionParser::parse_expr(Lexer&
                 // check if this is closing bracket of func()
                 if (!opstack_.empty()) {
                     int top = opstack_.back();
-                    if (is_function(top)) {
+                    if (my_is_function(top)) {
                         pop_onto_que();
                         int n = arg_cnt_.back() + 1;
                         int expected_n = get_function_narg(top);
@@ -846,7 +846,7 @@ void ExpressionParser::parse_expr(Lexer&
                     lex.throw_syntax_error("unexpected ',' after '?'");
                 // if we are here, opstack_.back() == OP_OPEN_ROUND
                 else if (opstack_.size() < 2 ||
-                         !is_function(*(opstack_.end() - 2)))
+                         !my_is_function(*(opstack_.end() - 2)))
                     lex.throw_syntax_error("',' outside of function");
                 else
                     // don't pop OP_OPEN_ROUND from the stack
