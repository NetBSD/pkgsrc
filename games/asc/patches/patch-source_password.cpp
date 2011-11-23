$NetBSD: patch-source_password.cpp,v 1.1 2011/11/23 23:29:45 joerg Exp $

--- source/password.cpp.orig	2011-11-23 16:24:05.000000000 +0000
+++ source/password.cpp
@@ -20,6 +20,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <stdlib.h>
 #include "password.h"
 #include "misc.h"
 
