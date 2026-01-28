$NetBSD: patch-src_LercLib_Lerc.cpp,v 1.1 2026/01/28 13:37:48 adam Exp $

https://github.com/Esri/lerc/issues/228

--- src/LercLib/Lerc.cpp.orig	2026-01-28 13:35:44.015198473 +0000
+++ src/LercLib/Lerc.cpp
@@ -26,6 +26,7 @@ Contributors:  Thomas Maurer
 #include "Lerc2.h"
 #include <typeinfo>
 #include <limits>
+#include <functional>
 
 #ifdef HAVE_LERC1_DECODE
   #include "Lerc1Decode/CntZImage.h"
