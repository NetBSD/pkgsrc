$NetBSD: patch-src_third__party_boost-1.70.0_boost_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2024/06/03 14:27:34 ryoon Exp $

* Fix static cast error under NetBSD 10.

--- src/third_party/boost-1.70.0/boost/asio/detail/impl/kqueue_reactor.ipp.orig	2024-06-03 12:57:16.711672651 +0000
+++ src/third_party/boost-1.70.0/boost/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,10 @@
 #include <boost/asio/detail/push_options.hpp>
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 999001400)
 # define BOOST_ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
