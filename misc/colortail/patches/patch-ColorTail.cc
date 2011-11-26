$NetBSD: patch-ColorTail.cc,v 1.1 2011/11/26 17:16:53 joerg Exp $

--- ColorTail.cc.orig	2011-11-26 15:16:04.000000000 +0000
+++ ColorTail.cc
@@ -17,7 +17,7 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
-#include <iostream.h>
+#include <iostream>
 #include <assert.h>
 #include <unistd.h>
 
@@ -26,6 +26,7 @@
 #include "OptionsParser.h"
 #include "Colorizer.h"
 
+using namespace std;
 
 // the constructor
 ColorTail::ColorTail()
