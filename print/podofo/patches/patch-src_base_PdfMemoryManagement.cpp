$NetBSD: patch-src_base_PdfMemoryManagement.cpp,v 1.2 2017/02/11 22:27:00 adam Exp $

Make sure SIZE_MAX is defined.

--- src/base/PdfMemoryManagement.cpp.orig	2017-01-29 12:26:55.000000000 +0000
+++ src/base/PdfMemoryManagement.cpp
@@ -31,6 +31,9 @@
  *   files in the program, then also delete it here.                       *
  ***************************************************************************/
 
+#define __STDC_LIMIT_MACROS 1
+#include <stdint.h>
+
 #include "PdfMemoryManagement.h"
 #include "PdfDefines.h"
 #include "PdfDefinesPrivate.h"
