$NetBSD: patch-src_core_ext_filters_client__channel_resolver_dns_c__ares_grpc__ares__ev__driver__posix.cc,v 1.2 2019/03/22 08:25:51 adam Exp $

Add SunOS support.

--- src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc.orig	2019-03-08 20:07:26.000000000 +0000
+++ src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc
@@ -23,6 +23,11 @@
 #include <ares.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 
 #include "src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver.h"
 
