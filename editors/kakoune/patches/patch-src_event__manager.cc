$NetBSD: patch-src_event__manager.cc,v 1.1 2019/07/25 15:34:48 nia Exp $

Include string.h for the benefit of FD_ZERO's memcpy needs on illumos.

--- src/event_manager.cc.orig	2019-07-01 12:07:29.000000000 +0000
+++ src/event_manager.cc
@@ -3,6 +3,7 @@
 #include "flags.hh"
 #include "ranges.hh"
 
+#include <string.h>
 #include <unistd.h>
 
 namespace Kakoune
