$NetBSD: patch-src_base_PdfMemoryManagement.cpp,v 1.1 2016/08/02 20:14:44 wiz Exp $

Make sure SIZE_MAX is defined.

--- src/base/PdfMemoryManagement.cpp.orig	2016-05-15 19:12:45.000000000 +0000
+++ src/base/PdfMemoryManagement.cpp
@@ -31,6 +31,9 @@
  *   files in the program, then also delete it here.                       *
  ***************************************************************************/
 
+#define __STDC_LIMIT_MACROS 1
+#include <stdint.h>
+
 #include "PdfMemoryManagement.h"
 #include "PdfDefinesPrivate.h"
 
