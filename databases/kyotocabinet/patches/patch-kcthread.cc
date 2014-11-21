$NetBSD: patch-kcthread.cc,v 1.1 2014/11/21 11:29:52 obache Exp $

* NetBSD also use generic method

--- kcthread.cc.orig	2012-05-24 16:27:59.000000000 +0000
+++ kcthread.cc
@@ -402,7 +402,7 @@ bool Mutex::lock_try() {
  * Try to get the lock.
  */
 bool Mutex::lock_try(double sec) {
-#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_) || defined(_SYS_CYGWIN_) || defined(_SYS_MACOSX_)
+#if defined(_SYS_MSVC_) || defined(_SYS_MINGW_) || defined(_SYS_CYGWIN_) || defined(_SYS_MACOSX_) || defined(_SYS_NETBSD_)
   _assert_(sec >= 0.0);
   if (lock_try()) return true;
   double end = time() + sec;
