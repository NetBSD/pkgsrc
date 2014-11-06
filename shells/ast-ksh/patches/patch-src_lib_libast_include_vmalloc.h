$NetBSD: patch-src_lib_libast_include_vmalloc.h,v 1.1 2014/11/06 12:25:36 joerg Exp $

--- src/lib/libast/include/vmalloc.h.orig	2014-11-06 00:44:20.000000000 +0000
+++ src/lib/libast/include/vmalloc.h
@@ -199,6 +199,7 @@ extern void		free _ARG_(( Void_t* ));
 extern void		cfree _ARG_(( Void_t* ));
 extern Void_t*		calloc _ARG_(( size_t, size_t ));
 extern Void_t*		memalign _ARG_(( size_t, size_t ));
+extern int		posix_memalign _ARG_(( Void_t **, size_t, size_t ));
 extern Void_t*		valloc _ARG_(( size_t ));
 #endif
 extern int		setregmax _ARG_(( int ));
@@ -247,6 +248,7 @@ _END_EXTERNS_
 #undef calloc
 #undef free
 #undef memalign
+#undef posix_memalign
 #undef valloc
 
 #if _map_malloc
@@ -256,6 +258,7 @@ _END_EXTERNS_
 #define calloc(n,s)		(_VMFL_(Vmregion), _ast_calloc((size_t)n, (size_t)(s)) )
 #define free(d)			(_VMFL_(Vmregion), _ast_free((Void_t*)(d)) )
 #define memalign(a,s)		(_VMFL_(Vmregion), _ast_memalign((size_t)(a),(size_t)(s)) )
+#define posix_memalign(p,a,s)	(_VMFL_(Vmregion), _ast_posix_memalign((Void_t**)(p),(size_t)(a),(size_t)(s)) )
 #define valloc(s)		(_VMFL_(Vmregion), _ast_valloc((size_t)(s) )
 
 #else
@@ -269,6 +272,7 @@ _END_EXTERNS_
 #define calloc(n,s)		(_VMFL_(Vmregion), calloc((size_t)n, (size_t)(s)) )
 #define free(d)			(_VMFL_(Vmregion), free((Void_t*)(d)) )
 #define memalign(a,s)		(_VMFL_(Vmregion), memalign((size_t)(a),(size_t)(s)) )
+#define posix_memalign(p,a,s)	(_VMFL_(Vmregion), posix_memalign((Void_t**)(p),(size_t)(a),(size_t)(s)) )
 #define valloc(s)		(_VMFL_(Vmregion), valloc((size_t)(s) )
 #ifndef strdup
 #define strdup(s)		( _VMFL_(Vmregion), (strdup)((char*)(s)) )
@@ -286,6 +290,8 @@ _END_EXTERNS_
 #define free(d)			(_VMFL_(Vmregion), _VMNM_(fre,/,*,*,/,e)((Void_t*)(d)) )
 #define memalign(a,s)		(_VMFL_(Vmregion), _VMNM_(memalig,/,*,*,/,n)\
 						((size_t)(a),(size_t)(s)) )
+#define posix_memalign(p,a,s)	(_VMFL_(Vmregion), _VMNM_(posix_memalig,/,*,*,/,n)\
+						((Void_t**)(p),(size_t)(a),(size_t)(s)) )
 #define valloc(s)		(_VMFL_(Vmregion), _VMNM_(vallo,/,*,*,/,c)\
 						((size_t)(s) )
 #ifndef strdup
