$NetBSD: patch-src_Helpers.cpp,v 1.4 2014/01/04 15:11:43 wiz Exp $

http://sourceforge.net/p/mp3diags/code/279/

--- src/Helpers.cpp.orig	2011-09-10 17:51:46.000000000 +0000
+++ src/Helpers.cpp
@@ -20,6 +20,7 @@
  ***************************************************************************/
 
 
+#include  <unistd.h>
 #include  <iostream>
 #include  "fstream_unicode.h"
 #include  <sstream>
