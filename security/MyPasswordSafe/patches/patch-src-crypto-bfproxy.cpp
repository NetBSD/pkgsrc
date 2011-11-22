$NetBSD: patch-src-crypto-bfproxy.cpp,v 1.1 2011/11/22 20:05:25 joerg Exp $

--- src/crypto/bfproxy.cpp.orig	2011-11-22 19:21:27.000000000 +0000
+++ src/crypto/bfproxy.cpp
@@ -17,6 +17,7 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 #include "bfproxy.hpp"
+#include <string.h>
 
 BFProxy::BFProxy(const unsigned char *key, int len)
 {
