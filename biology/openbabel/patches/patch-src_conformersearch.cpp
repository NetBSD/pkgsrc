$NetBSD: patch-src_conformersearch.cpp,v 1.1 2019/11/20 17:02:12 kamil Exp $

--- src/conformersearch.cpp.orig	2019-10-07 16:39:17.000000000 +0000
+++ src/conformersearch.cpp
@@ -23,6 +23,7 @@ GNU General Public License for more deta
 #include <openbabel/elements.h>
 #include <openbabel/bond.h>
 #include "rand.h"
+#include <algorithm>
 
 #if defined(_MSC_VER) && (_MSC_VER < 1800)
  #define OB_ISNAN _isnan
