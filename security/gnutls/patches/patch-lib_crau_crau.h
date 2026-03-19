$NetBSD: patch-lib_crau_crau.h,v 1.3 2026/03/19 17:29:37 jperkin Exp $

Limit support for [[__maybe_unused__]] to C23, fixing at least clang 15.

--- lib/crau/crau.h.orig	2026-03-19 17:19:53.894964618 +0000
+++ lib/crau/crau.h
@@ -251,10 +251,8 @@ void crau_data(struct crau_context_stack
 # else
 
 #  ifndef CRAU_MAYBE_UNUSED
-#   if defined(__has_c_attribute)
-#    if __has_c_attribute (__maybe_unused__)
-#     define CRAU_MAYBE_UNUSED [[__maybe_unused__]]
-#    endif
+#   if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
+#    define CRAU_MAYBE_UNUSED [[__maybe_unused__]]
 #   elif defined(__GNUC__)
 #    define CRAU_MAYBE_UNUSED __attribute__((__unused__))
 #   endif
