$NetBSD: patch-include_audacity_Types.h,v 1.1 2021/02/06 23:21:13 dbj Exp $

this include file references HAVE_VISIBILITY when it might not be defined
pull in Audacity.h which includes the appropriate config*.h file that sets it

--- include/audacity/Types.h.orig	2020-05-19 09:43:53.000000000 +0000
+++ include/audacity/Types.h
@@ -42,6 +42,7 @@
 #ifndef __AUDACITY_TYPES_H__
 #define __AUDACITY_TYPES_H__
 
+#include "Audacity.h" // for HAVE_VISIBILITY
 #include <algorithm>
 #include <functional>
 #include <type_traits>
