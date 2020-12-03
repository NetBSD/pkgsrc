$NetBSD: patch-src_signals.cxx,v 1.1 2020/12/03 13:29:08 nia Exp $

NetBSD needs signal.h included before sigaction can be used

--- src/signals.cxx.orig	2020-10-28 21:06:48.000000000 +0000
+++ src/signals.cxx
@@ -18,6 +18,7 @@
  */
 
 #include "Instance.hxx"
+#include <signal.h>
 
 void
 Instance::OnSigwinch() noexcept
