$NetBSD: patch-boost_test_impl_execution__monitor.ipp,v 1.4 2020/01/12 10:10:04 adam Exp $

--- boost/test/impl/execution_monitor.ipp.orig	2019-12-10 00:20:00.000000000 +0000
+++ boost/test/impl/execution_monitor.ipp
@@ -171,7 +171,8 @@ namespace { void _set_se_translator( voi
 #  if defined(SIGPOLL) && !defined(__CYGWIN__)                              && \
       !(defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))  && \
       !defined(__NetBSD__)                                                  && \
-      !defined(__QNXNTO__)
+      !defined(__QNXNTO__)                                                  && \
+      !defined(__DragonFly__)
 #    define BOOST_TEST_CATCH_SIGPOLL
 #  endif
 
