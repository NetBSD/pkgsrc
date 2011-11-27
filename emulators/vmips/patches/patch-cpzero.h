$NetBSD: patch-cpzero.h,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- cpzero.h.orig	2011-11-27 02:49:21.000000000 +0000
+++ cpzero.h
@@ -53,7 +53,7 @@ class CPZero
 	void tlbp_emulate(uint32 instr, uint32 pc);
 	void rfe_emulate(uint32 instr, uint32 pc);
 	void load_addr_trans_excp_info(uint32 va, uint32 vpn, TLBEntry *match);
-	int find_matching_tlb_entry(uint32 asid, uint32 asid);
+	int find_matching_tlb_entry(uint32 asid, uint32 asid2);
 	uint32 tlb_translate(uint32 seg, uint32 vaddr, int mode,
 		bool *cacheable, DeviceExc *client);
 
