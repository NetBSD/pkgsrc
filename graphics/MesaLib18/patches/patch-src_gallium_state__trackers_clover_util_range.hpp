$NetBSD: patch-src_gallium_state__trackers_clover_util_range.hpp,v 1.1 2018/10/07 23:49:31 ryoon Exp $

From FreeBSD ports for mesa 17.1.10:

From b95533b981af9a6687b41418e7cc2a5652fc2bdb Mon Sep 17 00:00:00 2001
Date: Fri, 7 Mar 2014 15:16:08 +0100
Subject: [PATCH 3/3] Work around for clang 3.4 which fails to build Clover

See:
  https://bugs.freedesktop.org/show_bug.cgi?id=74098#c3

--- src/gallium/state_trackers/clover/util/range.hpp.orig	2017-09-25 16:56:19.000000000 +0000
+++ src/gallium/state_trackers/clover/util/range.hpp
@@ -362,6 +362,14 @@ namespace clover {
       return { i, i + n };
    }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+   namespace detail {
+      template<typename T>
+      using fixup_function_type =
+         typename std::conditional<std::is_function<T>::value, T &, T>::type;
+   }
+#endif
+
    ///
    /// Create a range by transforming the contents of a number of
    /// source ranges \a rs element-wise using a provided functor \a f.
@@ -369,7 +377,11 @@ namespace clover {
    /// \sa adaptor_range.
    ///
    template<typename F, typename... Rs>
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+   adaptor_range<detail::fixup_function_type<F>, Rs...>
+#else
    adaptor_range<F, Rs...>
+#endif
    map(F &&f, Rs &&... rs) {
       return { std::forward<F>(f), std::forward<Rs>(rs)... };
    }
