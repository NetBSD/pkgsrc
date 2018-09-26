$NetBSD: patch-apg.c,v 1.1 2018/09/26 05:04:09 ryoon Exp $

* 11th for NULL termination. Fix -y segfault

--- apg.c.orig	2003-08-07 15:40:39.000000000 +0000
+++ apg.c
@@ -709,7 +709,7 @@ print_help (void)
 */
 char * crypt_passstring (const char *p)
 {
- char salt[10];
+ char salt[11];
  gen_rand_pass (salt, 10, 10, S_SL|S_CL|S_NB);
  return (crypt(p, salt));
 }
