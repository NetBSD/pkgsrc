$NetBSD: patch-src_cpu_i486.h,v 1.1 2026/07/16 11:03:33 nia Exp $

Hack around C++ math namespacing problems.

--- src/cpu/i486.h.orig	2026-07-15 23:27:06.185045081 +0000
+++ src/cpu/i486.h
@@ -16,12 +16,12 @@ THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 #define I486_IS_INCLUDED
 /* { */
 
+#include <cmath>
 #include <cstdint>
 #include <iostream>
 #include <map>
 #include <string>
 #include <type_traits>
-#include <math.h>
 
 #include "cpu.h"
 #include "ramrom.h"
@@ -654,7 +654,7 @@ class i486DXCommon : public CPU (public)
 				SRC=0.0;
 			}
 			statusWord&=~(STATUS_C0|STATUS_C2|STATUS_C3);
-			if(true==isnan(ST) || true==isnan(SRC))
+			if(true==std::isnan(ST) || true==std::isnan(SRC))
 			{
 				statusWord=(STATUS_C0|STATUS_C2|STATUS_C3);
 			}
