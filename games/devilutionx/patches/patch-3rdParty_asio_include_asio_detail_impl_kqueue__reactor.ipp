$NetBSD: patch-3rdParty_asio_include_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2020/03/30 19:36:39 joerg Exp $

--- 3rdParty/asio/include/asio/detail/impl/kqueue_reactor.ipp.orig	2020-03-09 00:37:54.000000000 +0000
+++ 3rdParty/asio/include/asio/detail/impl/kqueue_reactor.ipp
@@ -28,6 +28,9 @@
 #include "asio/detail/push_options.hpp"
 
 #if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+#if defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 999001500)
 # define ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
