$NetBSD: patch-package_konoha.compiler_compiler.c,v 1.2 2015/12/29 23:34:50 dholland Exp $

All the world's not an 80386.

--- package/konoha.compiler/compiler.c.orig	2015-03-28 23:05:26.000000000 +0000
+++ package/konoha.compiler/compiler.c
@@ -503,11 +503,19 @@ KMETHOD Compiler_getCurrentUline(CTX ctx
 
 KMETHOD Compiler_debug(CTX ctx, ksfp_t *sfp _RIX)
 {
+#if defined(__i386__) || defined(__x86_64__)
 	asm volatile("int3");
+#else
+	__builtin_trap();
+#endif
 }
 KMETHOD _debug_(CTX ctx, ksfp_t *sfp, kint_t a, kint_t b)
 {
+#if defined(__i386__) || defined(__x86_64__)
 	asm volatile("int3");
+#else
+	__builtin_trap();
+#endif
 	//void *p1 = (void*) a;
 	//void *p2 = (void*) b;
 	//fprintf(stderr, "%p %p %ld %ld %p %p\n", ctx, sfp, a, b, p1, p2);
@@ -515,7 +523,11 @@ KMETHOD _debug_(CTX ctx, ksfp_t *sfp, ki
 void __test__(void *a, void *b)
 {
 	fprintf(stderr, "%p %p\n", a, b);
+#if defined(__i386__) || defined(__x86_64__)
 	asm volatile("int3");
+#else
+	__builtin_trap();
+#endif
 }
 static void kook_compiler_emit(CTX ctx, kMethod *mtd)
 {
@@ -565,7 +577,11 @@ kMethod *compiler_LOOKUPMTD(CTX ctx, kOb
 KMETHOD Method_lazycompile(CTX ctx, ksfp_t *sfp _RIX) {
     kMethod *mtd = sfp[-1].mtdNC;
     assert(IS_Method(mtd));
-    asm volatile("int3");
+#if defined(__i386__) || defined(__x86_64__)
+	asm volatile("int3");
+#else
+	__builtin_trap();
+#endif
     CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
     knh_write_cid(ctx, cwb->w, (mtd)->cid);
     knh_putc(ctx, cwb->w, '.');
