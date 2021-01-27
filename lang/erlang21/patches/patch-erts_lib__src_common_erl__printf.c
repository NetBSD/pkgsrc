$NetBSD: patch-erts_lib__src_common_erl__printf.c,v 1.1 2021/01/27 16:13:51 jperkin Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- erts/lib_src/common/erl_printf.c.orig	2018-06-19 07:07:55.000000000 +0000
+++ erts/lib_src/common/erl_printf.c
@@ -27,6 +27,14 @@
 #include "config.h"
 #endif
 
+#ifdef __sun
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__-0 < 199901L
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include <string.h>
 #include "erl_errno.h"
 #ifdef __WIN32__
