$NetBSD: patch-Usage.cc,v 1.1 2011/11/26 17:16:53 joerg Exp $

--- Usage.cc.orig	2011-11-26 15:14:52.000000000 +0000
+++ Usage.cc
@@ -17,10 +17,12 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
-#include <iostream.h>
+#include <iostream>
 
 #include "Usage.h"
 
+using namespace std;
+
 Usage::Usage()
 {
 }
