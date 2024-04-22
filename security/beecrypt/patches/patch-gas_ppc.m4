$NetBSD: patch-gas_ppc.m4,v 1.1 2024/04/22 10:57:25 he Exp $

Add support for NetBSD/powerpc.

--- gas/ppc.m4.orig	2024-04-22 10:51:26.814669463 +0000
+++ gas/ppc.m4
@@ -62,6 +62,15 @@ define(LOAD_ADDRESS,`
 define(EXTERNAL_VARIABLE)
 ')
 
+ifelse(substr(ASM_OS,0,6),netbsd,`
+define(USE_NUMERIC_REGISTERS)
+define(LOAD_ADDRESS,`
+	lis $2,$1@ha
+	la $2,$1@l($2)
+')
+define(EXTERNAL_VARIABLE)
+')
+
 
 ifdef(`USE_NUMERIC_REGISTERS',`
 define(r0,0)
