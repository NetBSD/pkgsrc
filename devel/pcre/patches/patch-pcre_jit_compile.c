$NetBSD: patch-pcre_jit_compile.c,v 1.1 2017/02/22 03:22:57 sevan Exp $

CVE-2017-6004
https://web.nvd.nist.gov/view/vuln/detail?vulnId=CVE-2017-6004

--- pcre_jit_compile.c.orig	2016-07-02 15:53:59.000000000 +0000
+++ pcre_jit_compile.c
@@ -8111,7 +8111,7 @@ if (opcode == OP_COND || opcode == OP_SC
 
     if (*matchingpath == OP_FAIL)
       stacksize = 0;
-    if (*matchingpath == OP_RREF)
+    else if (*matchingpath == OP_RREF)
       {
       stacksize = GET2(matchingpath, 1);
       if (common->currententry == NULL)
