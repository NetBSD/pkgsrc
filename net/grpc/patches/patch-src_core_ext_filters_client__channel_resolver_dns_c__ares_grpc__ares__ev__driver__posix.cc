$NetBSD: patch-src_core_ext_filters_client__channel_resolver_dns_c__ares_grpc__ares__ev__driver__posix.cc,v 1.5 2023/11/02 12:46:44 wiz Exp $

Add SunOS support.

--- src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc.orig	2023-10-30 17:33:54.000000000 +0000
+++ src/core/ext/filters/client_channel/resolver/dns/c_ares/grpc_ares_ev_driver_posix.cc
@@ -22,6 +22,11 @@
 #if GRPC_ARES == 1 && defined(GRPC_POSIX_SOCKET_ARES_EV_DRIVER)
 
 // IWYU pragma: no_include <ares_build.h>
+#ifdef __sun
+#include <sys/filio.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 
 #include <sys/ioctl.h>
 #include <sys/socket.h>
