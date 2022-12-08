$NetBSD: patch-src_valgrind_fy-valgrind.h,v 1.1 2022/12/08 19:16:20 khorben Exp $

Replace <alloca.h> by <stdlib.h>
Already merged upstream (https://github.com/pantoniou/libfyaml/pull/50)

--- src/valgrind/fy-valgrind.h.orig	2022-01-19 10:32:21.000000000 +0000
+++ src/valgrind/fy-valgrind.h
@@ -19,7 +19,6 @@
 #include <getopt.h>
 #include <unistd.h>
 #include <limits.h>
-#include <alloca.h>
 #include <stdio.h>
 
 enum fy_valgrind_tool {
