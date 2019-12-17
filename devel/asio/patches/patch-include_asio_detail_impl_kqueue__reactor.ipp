$NetBSD: patch-include_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2019/12/17 01:58:24 gutteridge Exp $

* Fix build with recent NetBSD 9.99

--- include/asio/detail/impl/kqueue_reactor.ipp.orig	2016-09-18 22:24:38.000000000 +0000
+++ include/asio/detail/impl/kqueue_reactor.ipp
@@ -27,6 +27,10 @@
 #include "asio/detail/push_options.hpp"
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 # define ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
