$NetBSD: patch-src_infix2rpn.hxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - string constants are const char *

--- src/infix2rpn.hxx~	1998-05-12 16:49:08.000000000 +0000
+++ src/infix2rpn.hxx
@@ -70,8 +70,8 @@ private:
   void        ProcessOp(const operators op, STRSTACK *TheStack,  
 			STRING *result);
   void        RegisterError(const STRING &Error);
-  CHR        *op2string(const operators op);
-  CHR        *StandardizeOpName(const STRING op);
+  const CHR  *op2string(const operators op);
+  const CHR  *StandardizeOpName(const STRING op);
   INT         TermsWithNoOps;
   STRING      ErrorMessage;
   CHR         DefaultOp[MAX_OP_LEN];
