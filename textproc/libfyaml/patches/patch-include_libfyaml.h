$NetBSD: patch-include_libfyaml.h,v 1.1 2022/12/08 19:16:20 khorben Exp $

Replace <alloca.h> by <stdlib.h>
Already merged upstream (https://github.com/pantoniou/libfyaml/pull/50)

--- include/libfyaml.h.orig	2022-01-19 10:32:21.000000000 +0000
+++ include/libfyaml.h
@@ -37,7 +37,7 @@ extern "C" {
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#include <alloca.h>
+#include <stdlib.h>
 
 #if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
 #include <unistd.h>
