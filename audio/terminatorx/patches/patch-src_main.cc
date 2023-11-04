$NetBSD: patch-src_main.cc,v 1.2 2023/11/04 10:02:57 wiz Exp $

Use standard stdlib.h instead of non-standard malloc.h.

--- src/main.cc.orig	2022-08-25 14:40:07.000000000 +0000
+++ src/main.cc
@@ -26,7 +26,7 @@
 #define BENCH_CYCLES 100000
 
 #include "tX_maingui.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 #include <stdio.h>
 #ifndef WIN32
