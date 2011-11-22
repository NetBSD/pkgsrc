$NetBSD: patch-argparse.cpp,v 1.1 2011/11/22 18:04:58 joerg Exp $

--- argparse.cpp.orig	2011-11-22 17:30:01.000000000 +0000
+++ argparse.cpp
@@ -16,6 +16,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <stdlib.h>
 #include "argparse.h"
 #include <map>
 #include <list>
