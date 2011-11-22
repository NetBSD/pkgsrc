$NetBSD: patch-src-safeserializer.cpp,v 1.1 2011/11/22 20:05:25 joerg Exp $

--- src/safeserializer.cpp.orig	2011-11-22 18:59:13.000000000 +0000
+++ src/safeserializer.cpp
@@ -17,6 +17,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 #include <qstring.h>
+#include <algorithm>
 #include "safe.hpp"
 #include "safeserializer.hpp"
 #include "plaintextlizer.hpp"
