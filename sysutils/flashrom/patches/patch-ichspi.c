$NetBSD: patch-ichspi.c,v 1.1 2012/11/23 12:08:04 joerg Exp $

--- ichspi.c.orig	2012-11-22 21:15:44.000000000 +0000
+++ ichspi.c
@@ -1125,7 +1125,7 @@ static void ich_hwseq_set_addr(uint32_t 
 static uint32_t ich_hwseq_get_erase_block_size(unsigned int addr)
 {
 	uint8_t enc_berase;
-	static const uint32_t const dec_berase[4] = {
+	static const uint32_t dec_berase[4] = {
 		256,
 		4 * 1024,
 		8 * 1024,
