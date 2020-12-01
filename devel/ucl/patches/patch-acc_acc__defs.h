$NetBSD: patch-acc_acc__defs.h,v 1.1 2020/12/01 11:13:38 nia Exp $

Fix build with gcc >= 6.

--- acc/acc_defs.h.orig	2004-07-19 23:01:47.000000000 +0000
+++ acc/acc_defs.h
@@ -86,6 +86,11 @@
 ************************************************************************/
 
 /* This can be put into a header file but may get ignored by some compilers. */
+#if !defined(ACC_COMPILE_TIME_ASSERT_HEADER) && defined(__STDC_VERSION__)
+#  if __STDC_VERSION__ >= 201112L
+#    define ACC_COMPILE_TIME_ASSERT_HEADER(e) _Static_assert(e, #e);
+#  endif
+#endif
 #if !defined(ACC_COMPILE_TIME_ASSERT_HEADER)
 #  if (ACC_CC_AZTECC || ACC_CC_ZORTECHC)
 #    define ACC_COMPILE_TIME_ASSERT_HEADER(e)  extern int __acc_cta[1-!(e)];
@@ -99,6 +104,11 @@
 #endif
 
 /* This must appear within a function body. */
+#if !defined(ACC_COMPILE_TIME_ASSERT) && defined(__STDC_VERSION__)
+#  if __STDC_VERSION__ >= 201112L
+#    define ACC_COMPILE_TIME_ASSERT(e) _Static_assert(e, #e);
+#  endif
+#endif
 #if !defined(ACC_COMPILE_TIME_ASSERT)
 #  if (ACC_CC_AZTECC)
 #    define ACC_COMPILE_TIME_ASSERT(e)  {typedef int __acc_cta_t[1-!(e)];}
