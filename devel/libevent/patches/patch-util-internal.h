$NetBSD: patch-util-internal.h,v 1.1 2022/01/11 09:14:00 schmonz Exp $

Solaris 11 build with SunPro fails ('unexpected "("') if we use its
__has_attribute, so let's not.

--- util-internal.h.orig	2020-07-05 08:35:45.000000000 +0000
+++ util-internal.h
@@ -66,6 +66,9 @@ extern "C" {
 #  endif
 # endif /* __apple_build_version__ */
 #endif /*\ defined(__clang__) && __clang__ == 1 */
+#if defined(__SUNPRO_C)
+# undef EVUTIL_HAS_ATTRIBUTE
+#endif
 #ifndef EVUTIL_HAS_ATTRIBUTE
 # define EVUTIL_HAS_ATTRIBUTE(x) 0
 #endif
