$NetBSD: patch-modules_services__discovery_mtp.c,v 1.3 2022/05/11 09:23:48 jperkin Exp $

Include strings.h for rindex().

--- modules/services_discovery/mtp.c.orig	2017-11-24 15:29:18.000000000 +0000
+++ modules/services_discovery/mtp.c
@@ -30,6 +30,7 @@
 #include <vlc_services_discovery.h>
 
 #include <libmtp.h>
+#include <strings.h>
 
 /*****************************************************************************
  * Module descriptor
