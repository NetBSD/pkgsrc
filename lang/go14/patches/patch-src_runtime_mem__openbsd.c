$NetBSD: patch-src_runtime_mem__openbsd.c,v 1.1 2019/04/13 23:09:40 maya Exp $
$OpenBSD: patch-src_runtime_mem_openbsd_c,v 1.1 2018/04/05 17:47:30 jsing Exp $

OpenBSD 6.4 needs stack pages to be mapped with MAP_STACK.

Index: src/runtime/mem_openbsd.c
--- src/runtime/mem_openbsd.c.orig
+++ src/runtime/mem_openbsd.c
@@ -27,6 +27,17 @@ runtime·sysAlloc(uintptr n, uint64 *stat)
 	return v;
 }
 
+#pragma textflag NOSPLIT
+void
+runtime·sysMarkStack(void *v, uintptr n)
+{
+	void *p;
+
+	p = runtime·mmap(v, n, PROT_READ|PROT_WRITE, MAP_FIXED|MAP_ANON|MAP_PRIVATE|MAP_STACK, -1, 0);
+	if (p == ((void *)-1) || p != v)
+		runtime·throw("runtime: failed to mark stack");
+}
+
 void
 runtime·SysUnused(void *v, uintptr n)
 {
