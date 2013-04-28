$NetBSD: patch-source_interpret.c,v 1.1 2013/04/28 20:35:22 dholland Exp $

Silence gcc warnings about unsafe pointer casts.
(This code should be rewritten to use a union, but I'm leaving that 
for upstream.)

--- source/interpret.c~	2004-07-21 11:32:05.000000000 +0000
+++ source/interpret.c
@@ -1254,14 +1254,14 @@ static int pushArraySymVal(void)
 {
     Symbol *sym;
     DataValue *dataPtr;
-    int initEmpty;
+    intptr_t initEmpty;
     
     DISASM_RT(PC-1, 3);
     STACKDUMP(0, 3);
 
     sym = (Symbol *)*PC;
     PC++;
-    initEmpty = (int)*PC;
+    initEmpty = (intptr_t)*PC;
     PC++;
     
     if (sym->type == LOCAL_SYM) {
@@ -1872,7 +1872,7 @@ static int callSubroutine(void)
     char *errMsg;
     
     sym = (Symbol *)*PC++;
-    nArgs = (int)*PC++;
+    nArgs = (intptr_t)*PC++;
     
     DISASM_RT(PC-3, 3);
     STACKDUMP(nArgs, 3);
@@ -2064,7 +2064,7 @@ static int branch(void)
     DISASM_RT(PC-1, 2);
     STACKDUMP(0, 3);
 
-    PC += (int)*PC;
+    PC += (intptr_t)*PC;
     return STAT_OK;
 }
 
@@ -2085,7 +2085,7 @@ static int branchTrue(void)
     STACKDUMP(1, 3);
 
     POP_INT(value)
-    addr = PC + (int)*PC;
+    addr = PC + (intptr_t)*PC;
     PC++;
     
     if (value)
@@ -2101,7 +2101,7 @@ static int branchFalse(void)
     STACKDUMP(1, 3);
 
     POP_INT(value)
-    addr = PC + (int)*PC;
+    addr = PC + (intptr_t)*PC;
     PC++;
     
     if (!value)
@@ -2420,7 +2420,7 @@ static int arrayRef(void)
     char *keyString = NULL;
     int nDim;
     
-    nDim = (int)*PC;
+    nDim = (intptr_t)*PC;
     PC++;
 
     DISASM_RT(PC-2, 2);
@@ -2471,7 +2471,7 @@ static int arrayAssign(void)
     int errNum;
     int nDim;
     
-    nDim = (int)*PC;
+    nDim = (intptr_t)*PC;
     PC++;
 
     DISASM_RT(PC-2, 1);
@@ -2524,9 +2524,9 @@ static int arrayRefAndAssignSetup(void)
     char *keyString = NULL;
     int binaryOp, nDim;
     
-    binaryOp = (int)*PC;
+    binaryOp = (intptr_t)*PC;
     PC++;
-    nDim = (int)*PC;
+    nDim = (intptr_t)*PC;
     PC++;
 
     DISASM_RT(PC-3, 3);
@@ -2642,7 +2642,7 @@ static int arrayIter(void)
     PC++;
     iterator = (Symbol *)*PC;
     PC++;
-    branchAddr = PC + (int)*PC;
+    branchAddr = PC + (intptr_t)*PC;
     PC++;
 
     if (item->type == LOCAL_SYM) {
@@ -2739,7 +2739,7 @@ static int deleteArrayElement(void)
     char *keyString = NULL;
     int nDim;
 
-    nDim = (int)*PC;
+    nDim = (intptr_t)*PC;
     PC++;
 
     DISASM_RT(PC-2, 2);
