$NetBSD: patch-router_src_harness_include_mysql_harness_tty.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* TABDLY is an XSI standard not supported on all platforms (BSD)

--- router/src/harness/include/mysql/harness/tty.h.orig	2019-12-09 19:53:17.000000000 +0000
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
