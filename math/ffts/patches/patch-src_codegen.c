$NetBSD: patch-src_codegen.c,v 1.1 2016/01/22 14:57:41 gson Exp $

Provide the appropriate arguents to mmap on NetBSD.

--- src/codegen.c.orig	2014-01-05 22:32:16.000000000 +0000
+++ src/codegen.c
@@ -181,6 +181,8 @@ void ffts_generate_func_code(ffts_plan_t
 
 #ifdef __APPLE__
 	p->transform_base = mmap(NULL, p->transform_size, PROT_WRITE | PROT_READ, MAP_ANON | MAP_SHARED, -1, 0);
+#elif defined(__NetBSD__)
+	p->transform_base = mmap(NULL, p->transform_size, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_ANON | MAP_SHARED, -1, 0);
 #else
 #define MAP_ANONYMOUS 0x20	
 	p->transform_base = mmap(NULL, p->transform_size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
