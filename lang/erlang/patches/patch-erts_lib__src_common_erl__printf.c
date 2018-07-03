$NetBSD: patch-erts_lib__src_common_erl__printf.c,v 1.1 2018/07/03 11:01:21 fhajny Exp $

Unlock putc_unlocked in stdio.h.

--- erts/lib_src/common/erl_printf.c.orig	2018-06-19 07:07:55.000000000 +0000
+++ erts/lib_src/common/erl_printf.c
@@ -27,6 +27,10 @@
 #include "config.h"
 #endif
 
+#ifdef __sun
+#define _XOPEN_SOURCE 500
+#endif
+
 #include <string.h>
 #include "erl_errno.h"
 #ifdef __WIN32__
