$NetBSD: patch-boost_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2019/10/09 19:17:45 ryoon Exp $

* Fix build with recent NetBSD 9.99

--- boost/asio/detail/impl/kqueue_reactor.ipp.orig	2019-08-14 12:02:17.000000000 +0000
+++ boost/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,10 @@
 #include <boost/asio/detail/push_options.hpp>
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 # define BOOST_ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
