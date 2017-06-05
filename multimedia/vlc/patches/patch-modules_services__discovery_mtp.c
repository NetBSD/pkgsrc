$NetBSD: patch-modules_services__discovery_mtp.c,v 1.1.2.2 2017/06/05 09:01:01 bsiegert Exp $

Need strings.h for rindex().

--- modules/services_discovery/mtp.c.orig	2015-02-02 19:42:29.000000000 +0000
+++ modules/services_discovery/mtp.c
@@ -24,6 +24,7 @@
 # include "config.h"
 #endif
 
+#include <strings.h>
 #include <vlc_common.h>
 #include <vlc_plugin.h>
 #include <vlc_services_discovery.h>
