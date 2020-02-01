$NetBSD: patch-src_third__party_asio-master_asio_include_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2020/02/01 20:00:08 adam Exp $

Fix build with recent NetBSD 9.99.

--- src/third_party/asio-master/asio/include/asio/detail/impl/kqueue_reactor.ipp.orig	2020-01-26 17:31:51.341577994 +0000
+++ src/third_party/asio-master/asio/include/asio/detail/impl/kqueue_reactor.ipp
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
