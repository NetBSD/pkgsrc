$NetBSD: patch-util.c,v 1.1 2023/11/16 09:39:48 nia Exp $

Fix overlapping definition with libc.

--- util.c.orig	2020-12-17 01:31:33.000000000 +0000
+++ util.c
@@ -58,7 +58,7 @@ xmalloc(size_t n)
 }
 
 static void *
-reallocarray(void *p, size_t n, size_t m)
+samurai_reallocarray(void *p, size_t n, size_t m)
 {
 	if (m && n > SIZE_MAX / m) {
 		errno = ENOMEM;
@@ -70,7 +70,7 @@ reallocarray(void *p, size_t n, size_t m
 void *
 xreallocarray(void *p, size_t n, size_t m)
 {
-	p = reallocarray(p, n, m);
+	p = samurai_reallocarray(p, n, m);
 	if (!p)
 		fatal("reallocarray:");
 
