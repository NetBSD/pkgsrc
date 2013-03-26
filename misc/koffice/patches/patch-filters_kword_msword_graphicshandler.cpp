$NetBSD: patch-filters_kword_msword_graphicshandler.cpp,v 1.1 2013/03/26 23:27:09 joerg Exp $

--- filters/kword/msword/graphicshandler.cpp.orig	2013-03-24 21:00:42.000000000 +0000
+++ filters/kword/msword/graphicshandler.cpp
@@ -17,11 +17,11 @@
  * Boston, MA 02110-1301, USA.
 */
 
+#include <wv2/olestream.h>
+
 #include "graphicshandler.h"
 #include "document.h"
 
-#include <wv2/olestream.h>
-
 #include <KoStoreDevice.h>
 #include <KoSize.h>
 #include <kdebug.h>
