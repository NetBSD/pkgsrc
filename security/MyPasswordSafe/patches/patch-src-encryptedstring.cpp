$NetBSD: patch-src-encryptedstring.cpp,v 1.1 2011/11/22 20:05:25 joerg Exp $

--- src/encryptedstring.cpp.orig	2011-11-22 19:06:44.000000000 +0000
+++ src/encryptedstring.cpp
@@ -15,6 +15,8 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+#include <stdlib.h>
+#include <string.h>
 #include <time.h>
 #include <iostream>
 #include "pwsafe/Util.h"
