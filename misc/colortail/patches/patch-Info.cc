$NetBSD: patch-Info.cc,v 1.1 2011/11/26 17:16:53 joerg Exp $

--- Info.cc.orig	2011-11-26 15:16:33.000000000 +0000
+++ Info.cc
@@ -17,11 +17,13 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
-#include <iostream.h>
+#include <iostream>
 
 #include "Info.h"
 #include "config.h"
 
+using namespace std;
+
 Info::Info()
 {
 }
