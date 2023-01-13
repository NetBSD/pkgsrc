$NetBSD: patch-asio_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2023/01/13 16:08:03 wiz Exp $

Fix build on NetBSD>=10.
https://github.com/codership/galera/pull/632

--- asio/asio/detail/impl/kqueue_reactor.ipp.orig	2022-11-02 06:09:14.000000000 +0000
+++ asio/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,10 @@
 #include "asio/detail/push_options.hpp"
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if defined(__NetBSD__) && __NetBSD_Version__ < 1000000000
 # define ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
