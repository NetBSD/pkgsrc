$NetBSD: patch-builders_hardsid-builder_src_hardsid-builder.cpp,v 1.1 2012/02/05 09:00:13 sbd Exp $

--- builders/hardsid-builder/src/hardsid-builder.cpp.orig	2012-02-04 09:37:28.328184353 +0000
+++ builders/hardsid-builder/src/hardsid-builder.cpp
@@ -47,6 +47,7 @@
  ***************************************************************************/
 
 #include <stdio.h>
+#include <cstring>
 #include "config.h"
 
 #ifdef HAVE_EXCEPTIONS
