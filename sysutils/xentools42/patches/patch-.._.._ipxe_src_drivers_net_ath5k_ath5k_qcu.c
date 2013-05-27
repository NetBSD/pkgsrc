$NetBSD: patch-.._.._ipxe_src_drivers_net_ath5k_ath5k_qcu.c,v 1.1 2013/05/27 22:26:27 prlw1 Exp $

Build fix for
comparison between 'enum ath5k_tx_queue' and 'enum ath5k_tx_queue_id'

--- ../../ipxe/src/drivers/net/ath5k/ath5k_qcu.c.orig	2010-02-02 16:12:44.000000000 +0000
+++ ../../ipxe/src/drivers/net/ath5k/ath5k_qcu.c
@@ -268,7 +268,7 @@ int ath5k_hw_reset_tx_queue(struct ath5k
 		}
 
 		if (tq->tqi_ready_time &&
-		(tq->tqi_type != AR5K_TX_QUEUE_ID_CAB))
+		(tq->tqi_type != AR5K_TX_QUEUE_CAB))
 			ath5k_hw_reg_write(ah, AR5K_REG_SM(tq->tqi_ready_time,
 				AR5K_QCU_RDYTIMECFG_INTVAL) |
 				AR5K_QCU_RDYTIMECFG_ENABLE,
