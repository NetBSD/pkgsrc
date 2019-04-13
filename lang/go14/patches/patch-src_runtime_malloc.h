$NetBSD: patch-src_runtime_malloc.h,v 1.1 2019/04/13 23:09:40 maya Exp $
$OpenBSD: patch-src_runtime_malloc_h,v 1.1 2018/04/05 17:47:30 jsing Exp $

OpenBSD 6.4 needs stack pages to be mapped with MAP_STACK.

Index: src/runtime/malloc.h
--- src/runtime/malloc.h.orig
+++ src/runtime/malloc.h
@@ -197,6 +197,7 @@ struct MLink
 // if accessed.  Used only for debugging the runtime.
 
 void*	runtime·sysAlloc(uintptr nbytes, uint64 *stat);
+void	runtime·sysMarkStack(void *v, uintptr nbytes);
 void	runtime·SysFree(void *v, uintptr nbytes, uint64 *stat);
 void	runtime·SysUnused(void *v, uintptr nbytes);
 void	runtime·SysUsed(void *v, uintptr nbytes);
