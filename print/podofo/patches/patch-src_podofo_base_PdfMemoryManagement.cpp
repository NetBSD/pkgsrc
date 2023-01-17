$NetBSD: patch-src_podofo_base_PdfMemoryManagement.cpp,v 1.1 2023/01/17 14:01:57 spz Exp $

Make sure SIZE_MAX is defined.

--- src/podofo/base/PdfMemoryManagement.cpp.orig	2017-01-29 12:26:55.000000000 +0000
+++ src/podofo/base/PdfMemoryManagement.cpp
@@ -31,6 +31,9 @@
  *   files in the program, then also delete it here.                       *
  ***************************************************************************/
 
+#define __STDC_LIMIT_MACROS 1
+#include <stdint.h>
+
 #include "PdfMemoryManagement.h"
 #include "PdfDefines.h"
 #include "PdfDefinesPrivate.h"
