$NetBSD: patch-source_Property.cpp,v 1.1 2011/11/23 23:29:45 joerg Exp $

--- source/Property.cpp.orig	2011-11-23 16:22:56.000000000 +0000
+++ source/Property.cpp
@@ -16,6 +16,7 @@
  ***************************************************************************/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "Property.h"
 
 TextProperty::TextProperty()
