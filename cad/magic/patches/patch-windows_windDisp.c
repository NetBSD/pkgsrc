$NetBSD: patch-windows_windDisp.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

--- windows/windDisp.c.orig	2013-03-02 22:33:23.000000000 +0000
+++ windows/windDisp.c
@@ -76,7 +76,7 @@ bool windSomeSeparateRedisplay = FALSE;
  * ----------------------------------------------------------------------------
  */
 
-int windCheckOnlyWindow(MagWindow **w, WindClient client)
+void windCheckOnlyWindow(MagWindow **w, WindClient client)
 {
     MagWindow *sw, *tw;
     int wct = 0;
$NetBSD: patch-windows_windDisp.c,v 1.1 2013/03/03 01:11:11 joerg Exp $

--- windows/windDisp.c.orig	2013-03-02 22:33:23.000000000 +0000
+++ windows/windDisp.c
@@ -76,7 +76,7 @@ bool windSomeSeparateRedisplay = FALSE;
  * ----------------------------------------------------------------------------
  */
 
-int windCheckOnlyWindow(MagWindow **w, WindClient client)
+void windCheckOnlyWindow(MagWindow **w, WindClient client)
 {
     MagWindow *sw, *tw;
     int wct = 0;
