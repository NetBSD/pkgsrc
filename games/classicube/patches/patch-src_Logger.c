$NetBSD: patch-src_Logger.c,v 1.1 2025/05/15 07:32:01 nia Exp $

Add support for NetBSD/sparc64.

https://github.com/ClassiCube/ClassiCube/pull/1362

--- src/Logger.c.orig	2025-05-15 07:30:16.059074992 +0000
+++ src/Logger.c
@@ -672,6 +672,9 @@ static void PrintRegisters(cc_string* st
 	#define REG_GET_LR()      &r->__gregs[_REG_LR]
 	#define REG_GET_CTR()     &r->__gregs[_REG_CTR]
 	Dump_PPC()
+#elif defined __sparc__
+	#define REG_GET(ign, reg) &r->__gregs[_REG_##reg]
+	Dump_SPARC()
 #elif defined __mips__
 	#define REG_GNUM(num)     &r->__gregs[num]
 	#define REG_GET_PC()      &r->__gregs[_REG_EPC]
