$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_InfoSink.h,v 1.3 2023/02/05 09:05:29 he Exp $

--- gfx/angle/checkout/src/compiler/translator/InfoSink.h.orig	2020-08-28 21:32:36.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/InfoSink.h
@@ -7,7 +7,7 @@
 #ifndef COMPILER_TRANSLATOR_INFOSINK_H_
 #define COMPILER_TRANSLATOR_INFOSINK_H_
 
-#include <math.h>
+#include <cmath>
 #include <stdlib.h>
 #include "GLSLANG/ShaderLang.h"
 #include "compiler/translator/Common.h"
