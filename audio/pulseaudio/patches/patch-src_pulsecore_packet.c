$NetBSD: patch-src_pulsecore_packet.c,v 1.1 2015/12/18 11:21:17 taca Exp $

* Fix build problem on NetBSD 6 (gcc 4.5.3?), do not declare
  typedef of "pa_packet" again.

--- src/pulsecore/packet.c.orig	2015-09-10 04:51:41.000000000 +0000
+++ src/pulsecore/packet.c
@@ -32,7 +32,7 @@
 
 #define MAX_APPENDED_SIZE 128
 
-typedef struct pa_packet {
+struct pa_packet {
     PA_REFCNT_DECLARE;
     enum { PA_PACKET_APPENDED, PA_PACKET_DYNAMIC } type;
     size_t length;
@@ -40,7 +40,7 @@ typedef struct pa_packet {
     union {
         uint8_t appended[MAX_APPENDED_SIZE];
     } per_type;
-} pa_packet;
+};
 
 PA_STATIC_FLIST_DECLARE(packets, 0, pa_xfree);
 
