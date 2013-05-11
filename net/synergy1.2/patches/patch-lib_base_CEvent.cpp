$NetBSD: patch-lib_base_CEvent.cpp,v 1.1 2013/05/11 21:40:41 joerg Exp $

--- lib/base/CEvent.cpp.orig	2013-05-10 13:03:09.000000000 +0000
+++ lib/base/CEvent.cpp
@@ -12,6 +12,7 @@
  * GNU General Public License for more details.
  */
 
+#include <cstdlib>
 #include "CEvent.h"
 #include "CEventQueue.h"
 
