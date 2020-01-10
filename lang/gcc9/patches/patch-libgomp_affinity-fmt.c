$NetBSD: patch-libgomp_affinity-fmt.c,v 1.1 2020/01/10 07:49:48 rillig Exp $

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93219

On RedHat EL 6 x86_64:

> ../../../gcc-9.2.0/libgomp/affinity-fmt.c: In function 'gomp_print_string':
> ../../../gcc-9.2.0/libgomp/affinity-fmt.c:43:3: error: ignoring return value of 'fwrite', declared with attribute warn_unused_result [-Werror=unused-result]
>    43 |   fwrite (str, 1, len, stderr);
>       |   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~


--- libgomp/affinity-fmt.c.orig	2019-01-01 12:31:55.000000000 +0000
+++ libgomp/affinity-fmt.c
@@ -40,7 +40,7 @@
 void
 gomp_print_string (const char *str, size_t len)
 {
-  fwrite (str, 1, len, stderr);
+  (void)fwrite (str, 1, len, stderr);
 }
 
 void
