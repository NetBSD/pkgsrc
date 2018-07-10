$NetBSD: patch-gr-uhd_lib_usrp__block__impl.cc,v 1.1 2018/07/10 07:05:06 dbj Exp $

Fix compiling with Boost 1.67
patch from upstream https://github.com/gnuradio/gnuradio.git
commit 86fa85feef81e69dd1354b393118459340b94489

--- gr-uhd/lib/usrp_block_impl.cc.orig	2017-02-27 23:19:00.000000000 +0000
+++ gr-uhd/lib/usrp_block_impl.cc
@@ -128,7 +128,7 @@ bool usrp_block_impl::_wait_for_locked_s
 
   while (true) {
     if ((not first_lock_time.is_not_a_date_time()) and
-        (boost::get_system_time() > (first_lock_time + boost::posix_time::seconds(LOCK_TIMEOUT)))) {
+        (boost::get_system_time() > (first_lock_time + boost::posix_time::seconds(static_cast<long>(LOCK_TIMEOUT))))) {
       break;
     }
 
@@ -139,7 +139,7 @@ bool usrp_block_impl::_wait_for_locked_s
     else {
       first_lock_time = boost::system_time(); //reset to 'not a date time'
 
-      if (boost::get_system_time() > (start + boost::posix_time::seconds(LOCK_TIMEOUT))){
+      if (boost::get_system_time() > (start + boost::posix_time::seconds(static_cast<long>(LOCK_TIMEOUT)))){
         return false;
       }
     }
