$NetBSD: patch-src_frontends_xforms_FormMathsMatrix.C,v 1.1 2011/11/25 22:16:26 joerg Exp $

--- src/frontends/xforms/FormMathsMatrix.C.orig	2011-11-25 17:11:16.000000000 +0000
+++ src/frontends/xforms/FormMathsMatrix.C
@@ -16,6 +16,7 @@
 #endif
 
 #include <algorithm>
+#include <cstring>
 
 #include "FormMathsMatrix.h"
 #include "form_maths_matrix.h"
