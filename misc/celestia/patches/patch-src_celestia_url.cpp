$NetBSD: patch-src_celestia_url.cpp,v 1.1 2011/11/25 22:08:30 joerg Exp $

--- src/celestia/url.cpp.orig	2011-11-25 16:35:25.000000000 +0000
+++ src/celestia/url.cpp
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <cstring>
 #include <string>
 #include <stdio.h>
 #include "celestiacore.h"
