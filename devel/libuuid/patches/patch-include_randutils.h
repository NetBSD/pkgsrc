$NetBSD: patch-include_randutils.h,v 1.1 2021/07/25 04:00:34 dholland Exp $

Rename random_get_bytes to avoid symbol name conflict on Solaris.

--- include/randutils.h~	2018-06-04 07:57:02.792445890 +0000
+++ include/randutils.h
@@ -11,7 +11,7 @@ extern int rand_get_number(int low_n, in
 
 /* /dev/urandom based with fallback to rand() */
 extern int random_get_fd(void);
-extern void random_get_bytes(void *buf, size_t nbytes);
+extern void my_random_get_bytes(void *buf, size_t nbytes);
 extern const char *random_tell_source(void);
 
 #endif
