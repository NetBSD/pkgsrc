$NetBSD: patch-include_cmocka.h,v 1.5 2026/06/15 19:04:11 gdt Exp $

Do not use __attribute__ access on gcc < 12, per upstream bug report,
accessible by the awesome new gitlab URL syntax below:

https://gitlab.com/cmocka/cmocka/-/work_items?show=eyJpaWQiOiIxMTUiLCJmdWxsX3BhdGgiOiJjbW9ja2EvY21vY2thIiwiaWQiOjE4ODEyODQ4Mn0%3D  

--- include/cmocka.h.orig	2026-06-15 18:50:53.821237385 +0000
+++ include/cmocka.h
@@ -251,7 +251,7 @@ extern "C" {
  * https://gcc.gnu.org/onlinedocs/gcc-12.2.0/gcc/Common-Function-Attributes.html#Common-Function-Attributes
  */
 #ifdef __has_attribute
-#if __has_attribute(access)
+#if __has_attribute(access) && (!__GNUC__ || __GNUC__ >= 12)
 #define CMOCKA_NO_ACCESS_ATTRIBUTE \
     __attribute__((access(none, 1), access(none, 2)))
 #endif
