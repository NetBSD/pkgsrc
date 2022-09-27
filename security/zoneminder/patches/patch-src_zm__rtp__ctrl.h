$NetBSD: patch-src_zm__rtp__ctrl.h,v 1.2 2022/09/27 01:20:39 gdt Exp $

Work around:
  zm_rtp_ctrl.h:128:31: error: flexible array member 'RtpCtrlThread::RtcpPacket::<unnamed union>::Bye::srcN' in an otherwise empty 'struct RtpCtrlThread::RtcpPacket::<unnamed union>::Bye'

Not reported upstream because pkgsrc is out of date; to be done if this is not resolved by updating.

--- src/zm_rtp_ctrl.h.orig	2019-02-22 15:38:47.000000000 +0000
+++ src/zm_rtp_ctrl.h
@@ -125,7 +125,7 @@ private:
       // BYE
       struct
       {
-        uint32_t srcN[];   // list of sources
+        uint32_t srcN[0];   // list of sources
         // can't express trailing text for reason (what does this mean? it's not even english!)
       } bye;
      } body;
