$NetBSD: patch-config_gcc__hidden.h,v 1.1 2018/05/16 11:36:36 youri Exp $

Gjs needs some symbols.

--- config/gcc_hidden.h.orig	2018-04-28 01:04:01.000000000 +0000
+++ config/gcc_hidden.h
@@ -3,4 +3,4 @@
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 /* Begin all files as hidden visibility */
-#pragma GCC visibility push(hidden)
+#pragma GCC visibility push(default)
