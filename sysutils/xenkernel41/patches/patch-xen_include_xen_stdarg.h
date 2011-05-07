$NetBSD: patch-xen_include_xen_stdarg.h,v 1.1 2011/05/07 07:11:22 tnn Exp $

--- xen/include/xen/stdarg.h.orig	2011-03-25 10:43:01.000000000 +0000
+++ xen/include/xen/stdarg.h
@@ -1,5 +1,13 @@
+#ifndef _XEN_STDARG_H_
+#define _XEN_STDARG_H_
 #if defined(__OpenBSD__)
 #  include "/usr/include/stdarg.h"
+#elif defined(__NetBSD__)
+typedef __builtin_va_list va_list;
+#define va_start(ap, last)	__builtin_stdarg_start((ap), (last))
+#define va_end(ap)		__builtin_va_end(ap)
+#define va_arg			__builtin_va_arg
 #else
 #  include <stdarg.h>
 #endif
+#endif /* _XEN_STDARG_H_ */
