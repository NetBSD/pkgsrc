$NetBSD: patch-resolv_res__comp.c,v 1.1 2018/02/02 16:15:21 jperkin Exp $

Fix SunOS/clang.

--- resolv/res_comp.c.orig	2005-07-28 06:51:50.000000000 +0000
+++ resolv/res_comp.c
@@ -243,7 +243,7 @@ res_dnok(const char *dn) {
  * Note that one _ comes from C and the others come from us.
  */
 
-#ifdef SOLARIS2
+#if defined(SOLARIS2) && !defined(__clang__)
 #ifdef  __putlong
 #undef  __putlong
 #endif
