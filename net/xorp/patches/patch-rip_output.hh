$NetBSD: patch-rip_output.hh,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- rip/output.hh.orig	2020-04-16 15:12:16.319176979 +0000
+++ rip/output.hh
@@ -93,7 +93,7 @@ public:
     /**
      * Get number of packets placed on packet queue for output.
      */
-    void packets_sent() const			{ return _pkts_out; }
+    void packets_sent() const			{ return; }
 
 protected:
     /**
