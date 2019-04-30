$NetBSD: patch-lib_dns_dnsrps.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Use stdlib.h.

--- lib/dns/dnsrps.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/dnsrps.c
@@ -15,6 +15,7 @@
 
 #include <inttypes.h>
 #include <stdbool.h>
+#include <stdlib.h>
 
 #ifdef USE_DNSRPS
 
