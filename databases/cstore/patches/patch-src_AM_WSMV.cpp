$NetBSD: patch-src_AM_WSMV.cpp,v 1.1 2011/12/20 13:42:47 wiz Exp $

Add missing header.

--- src/AM/WSMV.cpp.orig	2005-07-06 04:06:24.000000000 +0000
+++ src/AM/WSMV.cpp
@@ -29,6 +29,7 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 #include <iostream>
+#include <stdlib.h>
 #include <fstream>
 #include <sstream>
 #include <string>
