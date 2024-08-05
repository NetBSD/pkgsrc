$NetBSD: patch-router_src_harness_include_mysql_harness_tty.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- router/src/harness/include/mysql/harness/tty.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ router/src/harness/include/mysql/harness/tty.h
@@ -201,7 +201,9 @@ class HARNESS_EXPORT Tty {
         // not on freebsd
         static constexpr const size_t kCarriangeReturnDelayMask = CRDLY;
 #endif
+#ifdef TABDLY
         static constexpr const size_t kHorizontalTabDelayMask = TABDLY;
+#endif
 #ifdef BSDLY
         // not on freebsd
         static constexpr const size_t kBackspaceDelayMask = BSDLY;
