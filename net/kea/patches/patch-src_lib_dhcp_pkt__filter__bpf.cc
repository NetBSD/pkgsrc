$NetBSD: patch-src_lib_dhcp_pkt__filter__bpf.cc,v 1.1 2024/11/13 14:37:28 taca Exp $

* Fix build problem on NetBSD; check if struct bpf_timeval is defined.

--- src/lib/dhcp/pkt_filter_bpf.cc.orig	2024-07-25 08:50:58.000000000 +0000
+++ src/lib/dhcp/pkt_filter_bpf.cc
@@ -547,6 +547,16 @@ PktFilterBPF::receive(Iface& iface, cons
     time_duration usecs(0, 0, 0, bpfh.bh_tstamp.tv_usec);
     timestamp += usecs;
     pkt->addPktEvent(PktEvent::SOCKET_RECEIVED, timestamp);
+#elif HAVE_BPF_TIMEVAL
+    // It is dangerous to cast and assign structures or structure pointers
+    // unless there is a guarantee that the members of struct timeval and
+    // struct bpf_timeval are defined in the same order and with the same
+    // types. Here, instead of casting, we are assigning the values to
+    // the structure members individually.
+    struct timeval timestamp;
+    timestamp.tv_sec = bpfh.bh_tstamp.tv_sec;
+    timestamp.tv_usec = bpfh.bh_tstamp.tv_usec;
+    pkt->addPktEvent(PktEvent::SOCKET_RECEIVED, timestamp);
 #else
     pkt->addPktEvent(PktEvent::SOCKET_RECEIVED, bpfh.bh_tstamp);
 #endif
