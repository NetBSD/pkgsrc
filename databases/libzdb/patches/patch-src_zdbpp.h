$NetBSD: patch-src_zdbpp.h,v 1.1 2022/10/28 17:58:03 he Exp $

Avoid "cannot be overloaded with" error by skipping doing
bind() both for `time_t` and `long long` if they're the same size.

--- src/zdbpp.h.orig	2022-10-28 13:27:26.964215539 +0000
+++ src/zdbpp.h
@@ -311,9 +311,11 @@ namespace zdb {
             this->setInt(parameterIndex, x);
         }
         
+#if !defined(__NetBSD__) || (defined(__NetBSD__) && (__SIZEOF_LONG_LONG__ != 8))
         void bind(int parameterIndex, long long x) {
             this->setLLong(parameterIndex, x);
         }
+#endif
         
         void bind(int parameterIndex, double x) {
             this->setDouble(parameterIndex, x);
