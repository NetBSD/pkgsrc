$NetBSD: patch-src_core_ext_filters_client__channel_resolver_dns_c__ares_grpc__ares__ev__driver__posix.cc,v 1.3 2020/08/07 06:45:57 adam Exp $

Add SunOS support.

--- src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc.orig	2020-08-04 20:02:23.000000000 +0000
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
 
 #include "absl/strings/str_cat.h"
 
