$NetBSD: patch-validator_libsres_res__debug.c,v 1.1 2013/04/01 12:21:54 joerg Exp $

Nice rant BTW, but it doesn't match reality at least on NetBSD 6.

--- validator/libsres/res_debug.c.orig	2013-03-31 20:34:36.000000000 +0000
+++ validator/libsres/res_debug.c
@@ -319,7 +319,7 @@ p_fqname(const u_char * cp, const u_char
  * And, for once, solaris has a better header than the rest, and has const
  * char ptrs in res_sym.
  */
-#if (defined(__APPLE__) || defined(sun) || defined(__CYGWIN__) || defined(linux)) && !defined(ANDROID)
+#if (defined(__APPLE__) || defined(sun) || defined(__CYGWIN__) || defined(linux) || defined(__NetBSD__)) && !defined(ANDROID)
 #define RES_SYM_TYPE res_sym
 #else
 struct res_sym_const {
