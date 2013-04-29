$NetBSD: patch-include_my__global.h,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- include/my_global.h.orig	2013-04-28 14:06:29.000000000 +0000
+++ include/my_global.h
@@ -465,7 +465,7 @@ typedef unsigned short ushort;
 #endif
 
 #define swap_variables(t, a, b) { t dummy; dummy= a; a= b; b= dummy; }
-#define test(a)		((a) ? 1 : 0)
+#define my_test(a)		((a) ? 1 : 0)
 #define set_if_bigger(a,b)  do { if ((a) < (b)) (a)=(b); } while(0)
 #define set_if_smaller(a,b) do { if ((a) > (b)) (a)=(b); } while(0)
 #define test_all_bits(a,b) (((a) & (b)) == (b))
@@ -1125,7 +1125,8 @@ typedef char		my_bool; /* Small bool */
 
 /* Provide __func__ macro definition for platforms that miss it. */
 #if __STDC_VERSION__ < 199901L
-#  if __GNUC__ >= 2
+#  if __GNUC__ >= 4
+#  elif __GNUC__ >= 2
 #    define __func__ __FUNCTION__
 #  else
 #    define __func__ "<unknown>"
