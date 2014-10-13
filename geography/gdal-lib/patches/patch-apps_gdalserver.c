$NetBSD: patch-apps_gdalserver.c,v 1.1 2014/10/13 20:52:44 joerg Exp $

--- apps/gdalserver.c.orig	2014-10-13 10:16:23.000000000 +0000
+++ apps/gdalserver.c
@@ -27,10 +27,6 @@
  * DEALINGS IN THE SOFTWARE.
  ****************************************************************************/
 
-#if defined(__STDC_VERSION__)
-#define _XOPEN_SOURCE
-#endif
-
 #include "cpl_port.h"
 
 #ifdef WIN32
