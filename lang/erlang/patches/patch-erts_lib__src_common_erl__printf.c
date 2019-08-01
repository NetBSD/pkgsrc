$NetBSD: patch-erts_lib__src_common_erl__printf.c,v 1.4 2019/08/01 11:43:00 nia Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- erts/lib_src/common/erl_printf.c.orig	2019-07-10 16:05:15.000000000 +0000
+++ erts/lib_src/common/erl_printf.c
@@ -32,6 +32,14 @@
     #define __EXTENSIONS__
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
