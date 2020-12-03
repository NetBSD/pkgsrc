$NetBSD: patch-src_swf.cpp,v 1.1 2020/12/03 22:23:33 nia Exp $

Add missing header for unlink etc.

--- src/swf.cpp.orig	2020-07-05 10:31:09.000000000 +0000
+++ src/swf.cpp
@@ -17,6 +17,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/
 
+#include <unistd.h>
 #include <string>
 #include <algorithm>
 #include "backends/security.h"
