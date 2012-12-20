$NetBSD: patch-main_vdp.c,v 1.1 2012/12/20 21:59:21 joerg Exp $

--- main/vdp.c.orig	2012-12-20 19:12:50.000000000 +0000
+++ main/vdp.c
@@ -90,7 +90,7 @@ void vdp_describe(void);
 void vdp_eventinit(void);
 void vdp_layer_simple(unsigned int layer, unsigned int priority,
                       uint8 *fielddata, unsigned int lineoffset);
-inline void vdp_plotcell(uint8 *patloc, uint8 palette, uint8 flags,
+static inline void vdp_plotcell(uint8 *patloc, uint8 palette, uint8 flags,
                          uint8 *cellloc, unsigned int lineoffset);
 void vdp_sprites(unsigned int line, uint8 *pridata, uint8 *outdata);
 int vdp_sprite_simple(unsigned int priority, uint8 *framedata,
@@ -1705,7 +1705,7 @@ void vdp_endfield(void)
      vdp_event_endline); */
 }
 
-inline void vdp_plotcell(uint8 *patloc, uint8 palette, uint8 flags,
+static inline void vdp_plotcell(uint8 *patloc, uint8 palette, uint8 flags,
                          uint8 *cellloc, unsigned int lineoffset)
 {
   int y, x;
