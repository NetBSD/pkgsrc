$NetBSD: patch-src_core_ext_filters_client__channel_resolver_dns_c__ares_grpc__ares__ev__driver__posix.cc,v 1.1 2018/05/15 15:20:18 jperkin Exp $

Add SunOS support.

--- src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc.orig	2018-04-13 18:08:11.000000000 +0000
+++ src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc
@@ -22,6 +22,11 @@
 
 #include <ares.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 
 #include "src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver.h"
 
