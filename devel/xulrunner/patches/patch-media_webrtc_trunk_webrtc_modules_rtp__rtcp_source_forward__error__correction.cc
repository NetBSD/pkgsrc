$NetBSD: patch-media_webrtc_trunk_webrtc_modules_rtp__rtcp_source_forward__error__correction.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2013-05-11 19:19:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -12,6 +12,7 @@
 
 #include <algorithm>
 #include <cassert>
+#include <cstdlib> // for abs()
 #include <cstring>
 #include <iterator>
 
