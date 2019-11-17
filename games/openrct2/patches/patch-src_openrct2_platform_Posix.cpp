$NetBSD: patch-src_openrct2_platform_Posix.cpp,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/platform/Posix.cpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/platform/Posix.cpp
@@ -7,7 +7,7 @@
  * OpenRCT2 is licensed under the GNU General Public License version 3.
  *****************************************************************************/
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 #    include <cstring>
 #    include <ctype.h>
