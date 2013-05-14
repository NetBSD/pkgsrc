$NetBSD: patch-src_core_StelUtils.cpp,v 1.1 2013/05/14 12:41:34 joerg Exp $

--- src/core/StelUtils.cpp.orig	2013-05-14 11:00:29.000000000 +0000
+++ src/core/StelUtils.cpp
@@ -17,6 +17,7 @@
  * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
  */
 
+#include <cstdlib>
 #include <cmath> // std::fmod
 
 #ifdef CYGWIN
