$NetBSD: patch-src_lib_libast_vmalloc_malloc.c,v 1.2 2014/11/10 18:02:53 joerg Exp $

--- src/lib/libast/vmalloc/malloc.c.orig	2012-06-28 06:52:46.000000000 +0000
+++ src/lib/libast/vmalloc/malloc.c
@@ -61,6 +61,10 @@ extern char*		getenv(const char*);
 #undef	mallinfo
 typedef struct ______mallinfo Mallinfo_t;
 #undef	mallopt
+#undef	memalign
+#define memalign	_ast_memalign
+#undef	posix_memalign
+#define posix_memalign	_ast_posix_memalign
 #undef	mstats
 typedef struct ______mstats Mstats_t;
 #undef	realloc
@@ -153,6 +157,7 @@ static int		_Vmpffd = -1;
 #undef malloc
 #undef mallopt
 #undef memalign
+#undef posix_memalign
 #undef mstats
 #undef realloc
 #undef valloc
@@ -166,6 +171,7 @@ static int		_Vmpffd = -1;
 #undef	free
 #undef	malloc
 #undef	memalign
+#undef	posix_memalign
 #undef	realloc
 
 #define calloc		_ast_calloc
@@ -173,6 +179,7 @@ static int		_Vmpffd = -1;
 #define free		_ast_free
 #define malloc		_ast_malloc
 #define memalign	_ast_memalign
+#define posix_memalign	_ast_posix_memalign
 #define realloc		_ast_realloc
 
 #endif
@@ -847,6 +854,9 @@ extern Void_t*	F1(_malloc, size_t,n) { r
 #if _lib_memalign
 extern Void_t*	F2(_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(_posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(_pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -864,6 +874,9 @@ extern Void_t*	F1(__malloc, size_t,n) { 
 #if _lib_memalign
 extern Void_t*	F2(__memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(__posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(__pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -881,6 +894,9 @@ extern Void_t*	F1(__libc_malloc, size_t,
 #if _lib_memalign
 extern Void_t*	F2(__libc_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(__libc_posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(__libc_pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -1015,6 +1031,11 @@ extern Void_t*	malloc _ARG_((size_t));
 extern Void_t*	memalign _ARG_((size_t, size_t));
 #endif
 
+#if _lib_posix_memalign
+#undef	posix_memalign
+extern Void_t*	posix_memalign _ARG_((size_t, size_t));
+#endif
+
 #if _lib_pvalloc
 #undef	pvalloc
 extern Void_t*	pvalloc _ARG_((size_t));
@@ -1039,6 +1060,9 @@ extern Void_t*	F1(_ast_malloc, size_t,n)
 #if _lib_memalign
 extern Void_t*	F2(_ast_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(_ast_posix_memalign, size_t,a, size_t,n) { return memalign(a, n); }
+#endif
 extern Void_t*	F2(_ast_realloc, Void_t*,p, size_t,n) { return realloc(p, n); }
 
 #endif
$NetBSD: patch-src_lib_libast_vmalloc_malloc.c,v 1.2 2014/11/10 18:02:53 joerg Exp $

--- src/lib/libast/vmalloc/malloc.c.orig	2012-06-28 06:52:46.000000000 +0000
+++ src/lib/libast/vmalloc/malloc.c
@@ -61,6 +61,10 @@ extern char*		getenv(const char*);
 #undef	mallinfo
 typedef struct ______mallinfo Mallinfo_t;
 #undef	mallopt
+#undef	memalign
+#define memalign	_ast_memalign
+#undef	posix_memalign
+#define posix_memalign	_ast_posix_memalign
 #undef	mstats
 typedef struct ______mstats Mstats_t;
 #undef	realloc
@@ -153,6 +157,7 @@ static int		_Vmpffd = -1;
 #undef malloc
 #undef mallopt
 #undef memalign
+#undef posix_memalign
 #undef mstats
 #undef realloc
 #undef valloc
@@ -166,6 +171,7 @@ static int		_Vmpffd = -1;
 #undef	free
 #undef	malloc
 #undef	memalign
+#undef	posix_memalign
 #undef	realloc
 
 #define calloc		_ast_calloc
@@ -173,6 +179,7 @@ static int		_Vmpffd = -1;
 #define free		_ast_free
 #define malloc		_ast_malloc
 #define memalign	_ast_memalign
+#define posix_memalign	_ast_posix_memalign
 #define realloc		_ast_realloc
 
 #endif
@@ -847,6 +854,9 @@ extern Void_t*	F1(_malloc, size_t,n) { r
 #if _lib_memalign
 extern Void_t*	F2(_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(_posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(_pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -864,6 +874,9 @@ extern Void_t*	F1(__malloc, size_t,n) { 
 #if _lib_memalign
 extern Void_t*	F2(__memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(__posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(__pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -881,6 +894,9 @@ extern Void_t*	F1(__libc_malloc, size_t,
 #if _lib_memalign
 extern Void_t*	F2(__libc_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(__libc_posix_memalign, size_t,a, size_t,n) { return posix_memalign(a, n); }
+#endif
 #if _lib_pvalloc
 extern Void_t*	F1(__libc_pvalloc, size_t,n) { return pvalloc(n); }
 #endif
@@ -1015,6 +1031,11 @@ extern Void_t*	malloc _ARG_((size_t));
 extern Void_t*	memalign _ARG_((size_t, size_t));
 #endif
 
+#if _lib_posix_memalign
+#undef	posix_memalign
+extern Void_t*	posix_memalign _ARG_((size_t, size_t));
+#endif
+
 #if _lib_pvalloc
 #undef	pvalloc
 extern Void_t*	pvalloc _ARG_((size_t));
@@ -1039,6 +1060,9 @@ extern Void_t*	F1(_ast_malloc, size_t,n)
 #if _lib_memalign
 extern Void_t*	F2(_ast_memalign, size_t,a, size_t,n) { return memalign(a, n); }
 #endif
+#if _lib_posix_memalign
+extern Void_t*	F2(_ast_posix_memalign, size_t,a, size_t,n) { return memalign(a, n); }
+#endif
 extern Void_t*	F2(_ast_realloc, Void_t*,p, size_t,n) { return realloc(p, n); }
 
 #endif
