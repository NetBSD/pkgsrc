$NetBSD: patch-src_lib_NUM3Parser.cpp,v 1.1 2020/05/17 21:45:51 rillig Exp $

NUM3Parser.cpp: In member function 'virtual bool libetonyek::NUM3Parser::parseDocument()':
NUM3Parser.cpp:46:3: error: 'for_each' is not a member of 'std'
   std::for_each(sheetListRefs.begin(), sheetListRefs.end(), std::bind(&NUM3Parser::parseSheet, this, std::placeholders::_1));

https://lists.freedesktop.org/archives/libreoffice/2020-May/date.html

--- src/lib/NUM3Parser.cpp.orig	2018-12-28 17:45:35.000000000 +0000
+++ src/lib/NUM3Parser.cpp
@@ -7,6 +7,7 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/.
  */
 
+#include <algorithm>
 #include <functional>
 
 #include "NUM3Parser.h"
