$NetBSD: patch-panel-plugin_weather-parsers.c,v 1.1 2018/05/17 09:59:28 jperkin Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- panel-plugin/weather-parsers.c.orig	2017-04-25 09:23:20.000000000 +0000
+++ panel-plugin/weather-parsers.c
@@ -25,8 +25,10 @@
  * before time.h and libxfce4panel.h (which includes glib.h).
  * Otherwise, they will be ignored.
  */
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED 1
+#endif
 #include "weather-parsers.h"
 #include "weather-translate.h"
 #include "weather-debug.h"
