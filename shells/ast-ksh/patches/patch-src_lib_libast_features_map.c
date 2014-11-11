$NetBSD: patch-src_lib_libast_features_map.c,v 1.3 2014/11/11 15:40:37 joerg Exp $

--- src/lib/libast/features/map.c.orig	2010-06-25 16:59:08.000000000 +0000
+++ src/lib/libast/features/map.c
@@ -432,6 +432,11 @@ main()
 	printf("#define memalign	_ast_memalign\n");
 	printf("extern void*		memalign(size_t, size_t);\n");
 #endif
+#if _lib_posix_memalign
+	printf("#undef	posix_memalign\n");
+	printf("#define posix_memalign	_ast_posix_memalign\n");
+	printf("extern int		posix_memalign(void **, size_t, size_t);\n");
+#endif
 #if _lib_mstats
 	printf("#undef	mstats\n");
 	printf("#define mstats		_ast_mstats\n");
