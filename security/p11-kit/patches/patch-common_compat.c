$NetBSD: patch-common_compat.c,v 1.4 2019/03/24 18:03:54 ryoon Exp $

- Hide getauxval() symbol because the implementation is incomplete
  and breaks for example openssl on NetBSD/evbarm
  https://github.com/p11-glue/p11-kit/issues/192

--- common/compat.c.orig	2018-08-10 09:54:46.000000000 +0000
+++ common/compat.c
@@ -791,6 +791,9 @@ mkdtemp (char *template)
 #ifndef HAVE_GETAUXVAL
 
 unsigned long
+#if defined(__GNUC__) || defined(__clang__)
+__attribute__((visibility("hidden")))
+#endif
 getauxval (unsigned long type)
 {
 	static unsigned long secure = 0UL;
