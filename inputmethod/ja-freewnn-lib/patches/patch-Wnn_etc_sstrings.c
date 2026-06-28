$NetBSD: patch-Wnn_etc_sstrings.c,v 1.1 2026/06/28 06:16:27 tsutsui Exp $

- Fix wnn_sStrncpy() to use the correct conversion direction.
  The function converts from the internal w_char representation to an
  external EUC char buffer, as wnn_sStrcpy() does. Calling eeuc_to_ieuc()
  was backwards and also triggers GCC 14 incompatible-pointer-types errors.
- Also appease possible signedness warnings

--- Wnn/etc/sstrings.c.orig	2026-06-23 18:52:06.978018310 +0000
+++ Wnn/etc/sstrings.c
@@ -54,7 +54,7 @@ wnn_sStrcpy (c, w)
 {
   register int ret;
 
-  ret = ieuc_to_eeuc (c, w, -1);
+  ret = ieuc_to_eeuc ((unsigned char *) c, w, -1);
   c[ret] = '\0';
   return (ret);
 }
@@ -100,7 +100,7 @@ wnn_sStrncpy (s1, s2, n)
      register w_char *s2;
      register int n;
 {
-  eeuc_to_ieuc (s1, s2, n / sizeof (w_char));
+  ieuc_to_eeuc ((unsigned char *) s1, s2, n);
   return s1;
 }
 
