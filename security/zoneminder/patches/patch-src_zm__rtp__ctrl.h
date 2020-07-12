$NetBSD: patch-src_zm__rtp__ctrl.h,v 1.1 2020/07/12 16:58:42 gdt Exp $

Work around:
  zm_rtp_ctrl.h:128:31: error: flexible array member 'RtpCtrlThread::RtcpPacket::<unnamed union>::Bye::srcN' in an otherwise empty 'struct RtpCtrlThread::RtcpPacket::<unnamed union>::Bye'

Not reported upstream because pkgsrc is out of date; to be done if this is not resolved by updating.

--- src/zm_rtp_ctrl.h.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zm_rtp_ctrl.h
@@ -125,7 +125,7 @@ private:
             // BYE
             struct Bye
             {
-                uint32_t srcN[];     // list of sources
+                uint32_t srcN[0];     // list of sources
                 // can't express trailing text for reason (what does this mean? it's not even english!)
             } bye;
          } body;
