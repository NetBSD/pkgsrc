$NetBSD: patch-src_mame_machine_naomibd.c,v 1.1 2011/04/04 12:09:03 wiz Exp $

bswap16 is a macro on NetBSD.
Sent upstream.

--- src/mame/machine/naomibd.c.orig	2011-03-29 08:50:06.000000000 +0000
+++ src/mame/machine/naomibd.c
@@ -516,14 +516,14 @@ static void naomibd_m1_decode(naomibd_st
 
 // Streaming M2/M3 protection and decompression
 
-INLINE UINT16 bswap16(UINT16 in)
+INLINE UINT16 naomi_bswap16(UINT16 in)
 {
     return ((in>>8) | (in<<8));
 }
 
 static UINT16 naomibd_get_decrypted_stream(naomibd_state *naomibd)
 {
-	UINT16 wordn = bswap16(naomibd->prot.ptr[naomibd->prot.count++]);
+	UINT16 wordn = naomi_bswap16(naomibd->prot.ptr[naomibd->prot.count++]);
 
 	naomibd->prot.aux_word = block_decrypt(naomibd->dc_gamekey, naomibd->dc_seqkey, naomibd->prot.seed++, wordn);
 	wordn = (naomibd->prot.last_word&~3) | (naomibd->prot.aux_word&3);
