$NetBSD: patch-src_plugins_charset_charset.c,v 1.1 2013/12/12 20:17:56 jperkin Exp $

Need strings.h for strcasecmp()

--- src/plugins/charset/charset.c.orig	2013-05-20 08:06:14.000000000 +0000
+++ src/plugins/charset/charset.c
@@ -25,6 +25,7 @@
 #define __USE_GNU
 #endif
 #include <string.h>
+#include <strings.h>
 #include <iconv.h>
 
 #include "../weechat-plugin.h"
