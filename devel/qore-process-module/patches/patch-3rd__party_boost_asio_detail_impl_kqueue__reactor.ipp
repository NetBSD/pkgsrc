$NetBSD: patch-3rd__party_boost_asio_detail_impl_kqueue__reactor.ipp,v 1.1 2026/01/04 00:26:42 wiz Exp $

--- 3rd_party/boost/asio/detail/impl/kqueue_reactor.ipp.orig	2026-01-04 00:22:14.679908300 +0000
+++ 3rd_party/boost/asio/detail/impl/kqueue_reactor.ipp
@@ -27,14 +27,8 @@
 
 #include <boost/asio/detail/push_options.hpp>
 
-#if defined(__NetBSD__)
-# define BOOST_ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
-    EV_SET(ev, ident, filt, flags, fflags, data, \
-      reinterpret_cast<intptr_t>(static_cast<void*>(udata)))
-#else
 # define BOOST_ASIO_KQUEUE_EV_SET(ev, ident, filt, flags, fflags, data, udata) \
     EV_SET(ev, ident, filt, flags, fflags, data, udata)
-#endif
 
 namespace boost {
 namespace asio {
