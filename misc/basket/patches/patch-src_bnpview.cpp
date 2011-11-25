$NetBSD: patch-src_bnpview.cpp,v 1.1 2011/11/25 22:07:34 joerg Exp $

--- src/bnpview.cpp.orig	2011-11-25 14:56:03.000000000 +0000
+++ src/bnpview.cpp
@@ -19,6 +19,7 @@
  ***************************************************************************/
 
  /// NEW:
+#include <cstdlib>
 
 #include <qwidgetstack.h>
 #include <qregexp.h>
