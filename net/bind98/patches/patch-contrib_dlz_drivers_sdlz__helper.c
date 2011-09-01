$NetBSD: patch-contrib_dlz_drivers_sdlz__helper.c,v 1.1 2011/09/01 03:44:35 taca Exp $

--- contrib/dlz/drivers/sdlz_helper.c.orig	2010-05-14 06:29:37.000000000 +0000
+++ contrib/dlz/drivers/sdlz_helper.c
@@ -50,7 +50,7 @@
  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#ifdef DLZ
+#ifdef CONTRIB_DLZ
 
 #include <config.h>
 
