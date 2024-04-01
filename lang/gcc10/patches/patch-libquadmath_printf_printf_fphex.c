$NetBSD: patch-libquadmath_printf_printf_fphex.c,v 1.1 2024/04/01 14:33:58 js Exp $

--- libquadmath/printf/printf_fphex.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libquadmath/printf/printf_fphex.c
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdbool.h>
+#include <unistd.h>
 #define NDEBUG
 #include <assert.h>
 #include "quadmath-rounding-mode.h"
