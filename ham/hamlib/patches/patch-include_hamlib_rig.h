$NetBSD: patch-include_hamlib_rig.h,v 1.1 2024/12/26 13:17:27 gdt Exp $

rig.h uses va_list without first include stdarg.h, as POSIX requires:
  https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/stdarg.h.html

https://github.com/Hamlib/Hamlib/issues/1644

--- include/hamlib/rig.h.orig	2024-12-26 12:58:56.497059287 +0000
+++ include/hamlib/rig.h
@@ -36,6 +36,7 @@
 #define HAMLIB_TRACE rig_debug(RIG_DEBUG_TRACE,"%s%s(%d) trace\n",spaces(STATE(rig)->depth), __FILE__, __LINE__)
 #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
 
+#include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
 #include <inttypes.h>
