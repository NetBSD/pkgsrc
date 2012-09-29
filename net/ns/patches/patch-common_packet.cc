$NetBSD: patch-common_packet.cc,v 1.1 2012/09/29 06:17:30 dholland Exp $

Suppress immensely noisy const warnings.

--- common/packet.cc~	2008-04-01 02:00:25.000000000 +0000
+++ common/packet.cc
@@ -41,7 +41,7 @@ static const char rcsid[] =
 #include "flags.h"
 
 p_info packet_info;
-char** p_info::name_;
+const char** p_info::name_;
 unsigned int p_info::nPkt_ = 0;
 PacketClassifier *p_info::pc_ = 0;
 
