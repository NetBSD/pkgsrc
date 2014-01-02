$NetBSD: patch-src_Helpers.cpp,v 1.3 2014/01/02 22:18:37 wiz Exp $

--- src/Helpers.cpp.orig	2011-09-10 17:51:46.000000000 +0000
+++ src/Helpers.cpp
@@ -20,6 +20,7 @@
  ***************************************************************************/
 
 
+#include  <unistd.h>
 #include  <iostream>
 #include  "fstream_unicode.h"
 #include  <sstream>
