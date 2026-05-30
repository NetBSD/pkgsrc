$NetBSD: patch-examples_svc__encoder__rtc.cc,v 1.2 2026/05/30 12:37:21 ryoon Exp $

--- examples/svc_encoder_rtc.cc.orig	2026-05-13 23:13:38.000000000 +0000
+++ examples/svc_encoder_rtc.cc
@@ -14,7 +14,7 @@
 
 #include <assert.h>
 #include <limits.h>
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
