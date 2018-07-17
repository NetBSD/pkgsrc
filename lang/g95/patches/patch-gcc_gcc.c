$NetBSD: patch-gcc_gcc.c,v 1.1 2018/07/17 21:38:39 joerg Exp $

--- ../gcc-4.1.2/gcc/gcc.c.orig	2018-07-17 15:30:56.297612662 +0000
+++ ../gcc-4.1.2/gcc/gcc.c
@@ -607,16 +607,8 @@ proper position among the other output f
 
 /* config.h can define LIBGCC_SPEC to override how and when libgcc.a is
    included.  */
-#ifndef LIBGCC_SPEC
-#if defined(REAL_LIBGCC_SPEC)
-#define LIBGCC_SPEC REAL_LIBGCC_SPEC
-#elif defined(LINK_LIBGCC_SPECIAL_1)
-/* Have gcc do the search for libgcc.a.  */
-#define LIBGCC_SPEC "libgcc.a%s"
-#else
-#define LIBGCC_SPEC "-lgcc"
-#endif
-#endif
+#undef LIBGCC_SPEC
+#define LIBGCC_SPEC %LIBGCC_SPEC%
 
 /* config.h can define STARTFILE_SPEC to override the default crt0 files.  */
 #ifndef STARTFILE_SPEC
