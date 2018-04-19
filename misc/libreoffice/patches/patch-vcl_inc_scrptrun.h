$NetBSD: patch-vcl_inc_scrptrun.h,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- vcl/inc/scrptrun.h.orig	2018-03-29 08:04:09.000000000 -0700
+++ vcl/inc/scrptrun.h	2018-04-17 18:02:20.629348624 -0700
@@ -45,6 +45,8 @@
 #include <unicode/uscript.h>
 #include <vector>
 
+using namespace U_ICU_NAMESPACE;
+
 namespace vcl {
 
 struct ParenStackEntry
