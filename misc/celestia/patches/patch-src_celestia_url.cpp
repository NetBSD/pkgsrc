$NetBSD: patch-src_celestia_url.cpp,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celestia/url.cpp.orig	2005-11-18 08:00:39.000000000 +0000
+++ src/celestia/url.cpp
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <cstring>
 #include <string>
 #include <stdio.h>
 #include "celestiacore.h"
