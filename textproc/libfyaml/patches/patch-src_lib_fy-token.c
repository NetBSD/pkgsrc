$NetBSD: patch-src_lib_fy-token.c,v 1.1 2022/12/08 19:16:20 khorben Exp $

Replace <alloca.h> by <stdlib.h>
Already merged upstream (https://github.com/pantoniou/libfyaml/pull/50)

--- src/lib/fy-token.c.orig	2022-01-19 10:32:21.000000000 +0000
+++ src/lib/fy-token.c
@@ -17,7 +17,6 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <stdarg.h>
-#include <alloca.h>
 
 #include <libfyaml.h>
 
