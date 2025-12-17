$NetBSD: patch-core_linux_context.cpp,v 1.3 2025/12/17 23:06:27 nia Exp $

Add support for NetBSD/i386.

--- core/linux/context.cpp.orig	2025-12-17 22:59:41.174130803 +0000
+++ core/linux/context.cpp
@@ -83,6 +83,11 @@ static void context_segfault(host_context_t* hostctx, 
 		bicopy<ToSegfault>(hostctx->esp, MCTX(.mc_esp));
 		bicopy<ToSegfault>(hostctx->eax, MCTX(.mc_eax));
 		bicopy<ToSegfault>(hostctx->ecx, MCTX(.mc_ecx));
+	#elif defined(__NetBSD__)
+		bicopy<ToSegfault>(hostctx->pc, MCTX(.__gregs[_REG_EIP]));
+		bicopy<ToSegfault>(hostctx->esp, MCTX(.__gregs[_REG_ESP]));
+		bicopy<ToSegfault>(hostctx->eax, MCTX(.__gregs[_REG_EAX]));
+		bicopy<ToSegfault>(hostctx->ecx, MCTX(.__gregs[_REG_ECX]));
 	#elif defined(__unix__)
 		bicopy<ToSegfault>(hostctx->pc, MCTX(.gregs[REG_EIP]));
 		bicopy<ToSegfault>(hostctx->esp, MCTX(.gregs[REG_ESP]));
