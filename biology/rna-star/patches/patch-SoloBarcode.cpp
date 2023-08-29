$NetBSD: patch-SoloBarcode.cpp,v 1.2 2023/08/29 21:49:57 bacon Exp $

# Portability

--- SoloBarcode.cpp.orig	2023-07-23 17:22:42.613062682 +0000
+++ SoloBarcode.cpp
@@ -3,6 +3,7 @@
 #include "SoloCommon.h"
 #include "SequenceFuns.h"
 #include "ParametersSolo.h"
+#include <cmath>
 
 void wlAddMismatches(uint32 nMM, uint32 cbLen, vector<uintCB> &wl, vector<uintCB> &wlEd1, vector<uint32> &wlInd1);
 
@@ -149,4 +150,4 @@ void wlAddMismatches(uint32 nMM, uint32 
             ++icb;
         };
     };
-};
\ No newline at end of file
+};
