$NetBSD: patch-Core_gb.c,v 1.1 2021/08/10 12:20:41 nia Exp $

Fix building with memcpy defined as a macro (FORTIFY_SOURCE/SSP).

--- Core/gb.c.orig	2021-08-01 13:19:40.000000000 +0000
+++ Core/gb.c
@@ -307,7 +307,7 @@ int GB_load_rom(GB_gameboy_t *gb, const 
 
 static void generate_gbs_entry(GB_gameboy_t *gb, uint8_t *data)
 {
-    memcpy(data, (uint8_t[]) {
+    memcpy(data, ((uint8_t[]) {
         0xCD, // Call $XXXX
         LE16(gb->gbs_header.init_address),
         LE16(gb->gbs_header.init_address) >> 8,
@@ -321,7 +321,7 @@ static void generate_gbs_entry(GB_gamebo
         LE16(gb->gbs_header.play_address) >> 8,
         0x18, // JR pc ± $XX
         -10   // To HALT
-    }, GBS_ENTRY_SIZE);
+    }), GBS_ENTRY_SIZE);
 }
 
 void GB_gbs_switch_track(GB_gameboy_t *gb, uint8_t track)
