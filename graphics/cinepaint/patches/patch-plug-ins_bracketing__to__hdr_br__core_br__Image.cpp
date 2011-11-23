$NetBSD: patch-plug-ins_bracketing__to__hdr_br__core_br__Image.cpp,v 1.1 2011/11/23 23:30:30 joerg Exp $

--- plug-ins/bracketing_to_hdr/br_core/br_Image.cpp.orig	2011-11-23 16:53:30.000000000 +0000
+++ plug-ins/bracketing_to_hdr/br_core/br_Image.cpp
@@ -26,6 +26,7 @@
 */
 #include <iostream>
 #include <cmath>                    // pow()
+#include <cstring>
 
 #include "br_types.hpp"             // ImageID
 #include "br_enums.hpp"             // DataType, ReportWhat
