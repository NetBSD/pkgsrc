$NetBSD: patch-3rdparty_asio_include_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2019/10/17 10:18:37 wiz Exp $

NetBSD 9.99.14 changed the type to be more compatible to other operating systems.

--- 3rdparty/asio/include/asio/detail/impl/kqueue_reactor.ipp.orig	2019-08-02 19:05:18.000000000 +0000
+++ 3rdparty/asio/include/asio/detail/impl/kqueue_reactor.ipp
@@ -16,6 +16,10 @@
 # pragma once
 #endif // defined(_MSC_VER) && (_MSC_VER >= 1200)
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include "asio/detail/config.hpp"
 
 #if defined(ASIO_HAS_KQUEUE)
@@ -27,7 +31,7 @@
 
 #include "asio/detail/push_options.hpp"
 
-#if defined(__NetBSD__)
+#if defined(__NetBSD__) && (__NetBSD_Version__ <= 999001400)
 # define ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, \
       reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
