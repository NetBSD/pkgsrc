$NetBSD: patch-sdk_asio-1.12.1_asio_detail_impl_kqueue__reactor.ipp,v 1.2 2022/10/17 16:50:03 andvar Exp $

Deal with kqueue changes in NetBSD.

--- sdk/asio-1.12.1/asio/detail/impl/kqueue_reactor.ipp.orig	2020-03-26 12:10:17.919075389 +0000
+++ sdk/asio-1.12.1/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,10 @@
 #include "asio/detail/push_options.hpp"
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 # define ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
