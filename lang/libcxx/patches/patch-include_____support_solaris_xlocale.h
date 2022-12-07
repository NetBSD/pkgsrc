$NetBSD: patch-include_____support_solaris_xlocale.h,v 1.1 2022/12/07 10:40:34 jperkin Exp $

Fix SunOS support.

--- include/__support/solaris/xlocale.h.orig	2022-11-29 10:05:58.000000000 +0000
+++ include/__support/solaris/xlocale.h
@@ -13,6 +13,9 @@
 #ifndef __XLOCALE_H_INCLUDED
 #define __XLOCALE_H_INCLUDED
 
+#include <cstdlib>
+#include <cwchar>
+#include <__support/xlocale/__strtonum_fallback.h>
 #include <stdlib.h>
 
 #ifdef __cplusplus
@@ -31,6 +34,7 @@ int tolower_l(int __c, locale_t __l);
 struct lconv *localeconv(void);
 struct lconv *localeconv_l(locale_t __l);
 
+#if 0
 // FIXME: These are quick-and-dirty hacks to make things pretend to work
 inline _LIBCPP_HIDE_FROM_ABI long long
 strtoll_l(const char *__nptr, char **__endptr, int __base, locale_t __loc) {
@@ -66,6 +70,7 @@ inline _LIBCPP_HIDE_FROM_ABI long double
 strtold_l(const char *__nptr, char **__endptr, locale_t __loc) {
   return ::strtold(__nptr, __endptr);
 }
+#endif
 
 
 #ifdef __cplusplus
