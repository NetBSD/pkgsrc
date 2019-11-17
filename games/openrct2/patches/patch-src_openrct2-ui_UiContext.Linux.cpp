$NetBSD: patch-src_openrct2-ui_UiContext.Linux.cpp,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2-ui/UiContext.Linux.cpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2-ui/UiContext.Linux.cpp
@@ -7,7 +7,7 @@
  * OpenRCT2 is licensed under the GNU General Public License version 3.
  *****************************************************************************/
 
-#if (defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__EMSCRIPTEN__)) && !defined(__ANDROID__)
 
 #    include "UiContext.h"
 
