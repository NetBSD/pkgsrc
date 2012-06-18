# $NetBSD: patch-hw-esp.c,v 1.1 2012/06/18 19:25:38 martin Exp $

# Commands that do not use DMA do not need to be defered untill DMA is
# enabled, https://bugs.launchpad.net/qemu/+bug/1014099

--- hw/esp.c.orig	2012-06-01 11:13:13.000000000 +0200
+++ hw/esp.c	2012-06-18 01:43:34.000000000 +0200
@@ -270,7 +270,7 @@ static void handle_satn(ESPState *s)
     uint8_t buf[32];
     int len;
 
-    if (!s->dma_enabled) {
+    if (s->dma && !s->dma_enabled) {
         s->dma_cb = handle_satn;
         return;
     }
@@ -284,7 +284,7 @@ static void handle_s_without_atn(ESPStat
     uint8_t buf[32];
     int len;
 
-    if (!s->dma_enabled) {
+    if (s->dma && !s->dma_enabled) {
         s->dma_cb = handle_s_without_atn;
         return;
     }
@@ -296,7 +296,7 @@ static void handle_s_without_atn(ESPStat
 
 static void handle_satn_stop(ESPState *s)
 {
-    if (!s->dma_enabled) {
+    if (s->dma && !s->dma_enabled) {
         s->dma_cb = handle_satn_stop;
         return;
     }
