$NetBSD: patch-src_openrct2_platform_Posix.cpp,v 1.2 2023/08/12 15:13:07 triaxx Exp $

Support NetBSD.

--- src/openrct2/platform/Posix.cpp.orig	2020-11-01 19:00:01.000000000 +0000
+++ src/openrct2/platform/Posix.cpp
@@ -7,7 +7,7 @@
  * OpenRCT2 is licensed under the GNU General Public License version 3.
  *****************************************************************************/
 
-#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__)
+#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 #    include "../OpenRCT2.h"
 #    include "../config/Config.h"
