$NetBSD: patch-src_crypto_twofish.cpp,v 1.1 2011/11/24 13:37:22 joerg Exp $

--- src/crypto/twofish.cpp.orig	2011-11-24 01:43:03.000000000 +0000
+++ src/crypto/twofish.cpp
@@ -171,6 +171,7 @@
  * Standard include files will probably be ok.
  */
 
+#include <stdlib.h>
 #include <qstring.h>     /* for memset(), memcpy(), and memcmp() */
 #include "twofish.h"
 
