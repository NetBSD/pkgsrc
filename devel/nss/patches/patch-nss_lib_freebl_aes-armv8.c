$NetBSD: patch-nss_lib_freebl_aes-armv8.c,v 1.1 2020/04/12 12:19:20 tnn Exp $

Explicitly enable the ARMv8 crypto extensions as the compiler doesn't
seem to do it for us.
https://mail-index.netbsd.org/port-arm/2020/04/12/msg006603.html

--- nss/lib/freebl/aes-armv8.c.orig	2020-03-06 18:44:20.000000000 +0000
+++ nss/lib/freebl/aes-armv8.c
@@ -2,6 +2,10 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#ifdef __NetBSD__
+asm(".arch_extension crypto");
+#endif
+
 #include "secerr.h"
 #include "rijndael.h"
 
