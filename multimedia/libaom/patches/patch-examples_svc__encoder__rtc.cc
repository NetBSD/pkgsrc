$NetBSD: patch-examples_svc__encoder__rtc.cc,v 1.1 2025/02/26 15:58:57 ryoon Exp $

--- examples/svc_encoder_rtc.cc.orig	2025-02-13 15:21:06.075305022 +0000
+++ examples/svc_encoder_rtc.cc
@@ -15,7 +15,7 @@
 #include <assert.h>
 #include <inttypes.h>
 #include <limits.h>
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
