$NetBSD: patch-xen_include_xen_stdarg.h,v 1.3 2011/08/14 20:42:41 abs Exp $

--- xen/include/xen/stdarg.h.orig	2011-06-14 16:03:46.000000000 +0000
+++ xen/include/xen/stdarg.h
@@ -1,8 +1,19 @@
 #if defined(__OpenBSD__)
 #  include "/usr/include/stdarg.h"
 #elif defined (__NetBSD__)
+   /* Why not just include stdarg.h like everyone else? should explain */
    typedef __builtin_va_list va_list;
-#  define va_start(ap, last)    __builtin_stdarg_start((ap), (last))
+#  ifdef __GNUC__
+#    define __GNUC_PREREQ__(x, y)                                           \
+        ((__GNUC__ == (x) && __GNUC_MINOR__ >= (y)) ||                  \
+         (__GNUC__ > (x)))
+#  else
+#    define __GNUC_PREREQ__(x, y)   0
+#  endif
+#  if !__GNUC_PREREQ__(4, 5)
+#    define __builtin_va_start(ap, last)    __builtin_stdarg_start((ap), (last))
+#  endif
+#  define va_start(ap, last)    __builtin_va_start((ap), (last))
 #  define va_end(ap)            __builtin_va_end(ap)
 #  define va_arg                __builtin_va_arg
 #else
