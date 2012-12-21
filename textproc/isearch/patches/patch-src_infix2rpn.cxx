$NetBSD: patch-src_infix2rpn.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use "std" qualification
   - string constants are const char *

--- src/infix2rpn.cxx~	1998-05-12 16:49:08.000000000 +0000
+++ src/infix2rpn.cxx
@@ -241,7 +241,7 @@ INFIX2RPN::ProcessOp(const operators op,
 
 //standardizes the various possible representations of
 //the various operators.
-CHR *
+const CHR *
 INFIX2RPN::StandardizeOpName(const STRING op) {
   if ( (op ^= "AND") || (op == "&&") )
     return "AND";
@@ -261,13 +261,13 @@ INFIX2RPN::StandardizeOpName(const STRIN
 
 
 //converts the internal operator token name to a standard string
-CHR *
+const CHR *
 INFIX2RPN::op2string(const operators op) {
   switch(op) {
   case LeftParen:
   case NOP:
     //shouldn't happen, but makes gcc -WALL happy.
-    cerr << "LeftParen || NOP?" << endl;
+    std::cerr << "LeftParen || NOP?" << std::endl;
     break;
   case BoolOR:
     return "OR";
