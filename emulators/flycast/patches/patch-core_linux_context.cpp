$NetBSD: patch-core_linux_context.cpp,v 1.1 2023/07/02 17:32:30 nia Exp $

Fix build on NetBSD/amd64.

--- core/linux/context.cpp.orig	2023-02-15 17:59:44.000000000 +0000
+++ core/linux/context.cpp
@@ -84,9 +84,9 @@ static void context_segfault(host_contex
 		bicopy<ToSegfault>(hostctx->pc, MCTX(.mc_rip));
 	#elif defined(__NetBSD__)
 		bicopy<ToSegfault>(hostctx->pc, MCTX(.__gregs[_REG_RIP]));
-		bicopy<ToSegfault>(hostctx->rsp, MCTX(.__gregs[REG_RSP]));
-		bicopy<ToSegfault>(hostctx->r9, MCTX(.__gregs[REG_R9]));
-		bicopy<ToSegfault>(hostctx->rdi, MCTX(.__gregs[REG_RDI]));
+		bicopy<ToSegfault>(hostctx->rsp, MCTX(.__gregs[_REG_RSP]));
+		bicopy<ToSegfault>(hostctx->r9, MCTX(.__gregs[_REG_R9]));
+		bicopy<ToSegfault>(hostctx->rdi, MCTX(.__gregs[_REG_RDI]));
 	#elif defined(__unix__)
 		bicopy<ToSegfault>(hostctx->pc, MCTX(.gregs[REG_RIP]));
 		bicopy<ToSegfault>(hostctx->rsp, MCTX(.gregs[REG_RSP]));
