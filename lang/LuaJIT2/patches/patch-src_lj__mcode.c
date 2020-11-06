$NetBSD: patch-src_lj__mcode.c,v 1.1 2020/11/06 12:15:53 nia Exp $

Make PaX-MPROTECT safe for NetBSD.

--- src/lj_mcode.c.orig	2017-05-01 18:11:00.000000000 +0000
+++ src/lj_mcode.c
@@ -99,7 +99,11 @@ static int mcode_setprot(void *p, size_t
 
 static void *mcode_alloc_at(jit_State *J, uintptr_t hint, size_t sz, int prot)
 {
+#ifdef PROT_MPROTECT
+  void *p = mmap((void *)hint, sz, prot | PROT_MPROTECT(MCPROT_RWX), MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+#else
   void *p = mmap((void *)hint, sz, prot, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
+#endif
   if (p == MAP_FAILED) {
     if (!hint) lj_trace_err(J, LJ_TRERR_MCODEAL);
     p = NULL;
@@ -255,7 +259,7 @@ static void *mcode_alloc(jit_State *J, s
 /* All memory addresses are reachable by relative jumps. */
 static void *mcode_alloc(jit_State *J, size_t sz)
 {
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__)
   /* Allow better executable memory allocation for OpenBSD W^X mode. */
   void *p = mcode_alloc_at(J, 0, sz, MCPROT_RUN);
   if (p && mcode_setprot(p, sz, MCPROT_GEN)) {
