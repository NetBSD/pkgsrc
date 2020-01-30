$NetBSD: patch-src_cmd3.c,v 1.1 2020/01/30 13:56:12 pho Exp $

Use the correct format specifier.

Local Variables:
coding: euc-jp
End:

--- src/cmd3.c.orig	2004-03-28 05:05:36.000000000 +0000
+++ src/cmd3.c
@@ -45,12 +45,12 @@ void do_cmd_inven(void)
 	item_tester_full = FALSE;
 
 #ifdef JP
-	sprintf(out_val, "持ち物： 合計 %3d.%1d kg (限界の%ld%%) コマンド: ",
+	sprintf(out_val, "持ち物： 合計 %3d.%1d kg (限界の%d%%) コマンド: ",
 	    lbtokg1(p_ptr->total_weight) , lbtokg2(p_ptr->total_weight) ,
 	    (p_ptr->total_weight * 100) / ((adj_str_wgt[p_ptr->stat_ind[A_STR]] * (p_ptr->pclass == CLASS_BERSERKER ? 150 : 100)) 
 / 2));
 #else
-	sprintf(out_val, "Inventory: carrying %d.%d pounds (%ld%% of capacity). Command: ",
+	sprintf(out_val, "Inventory: carrying %d.%d pounds (%d%% of capacity). Command: ",
 	    (int)(p_ptr->total_weight / 10), (int)(p_ptr->total_weight % 10),
 	    (p_ptr->total_weight * 100) / ((adj_str_wgt[p_ptr->stat_ind[A_STR]] * (p_ptr->pclass == CLASS_BERSERKER ? 150 : 100)) / 2));
 #endif
@@ -120,12 +120,12 @@ void do_cmd_equip(void)
 
 	/* Build a prompt */
 #ifdef JP
-	sprintf(out_val, "装備： 合計 %3d.%1d kg (限界の%ld%%) コマンド: ",
+	sprintf(out_val, "装備： 合計 %3d.%1d kg (限界の%d%%) コマンド: ",
 	    lbtokg1(p_ptr->total_weight) , lbtokg2(p_ptr->total_weight) ,
 	    (p_ptr->total_weight * 100) / ((adj_str_wgt[p_ptr->stat_ind[A_STR]] * (p_ptr->pclass == CLASS_BERSERKER ? 150 : 100)) 
 / 2));
 #else
-	sprintf(out_val, "Equipment: carrying %d.%d pounds (%ld%% of capacity). Command: ",
+	sprintf(out_val, "Equipment: carrying %d.%d pounds (%d%% of capacity). Command: ",
 	    (int)(p_ptr->total_weight / 10), (int)(p_ptr->total_weight % 10),
 	    (p_ptr->total_weight * 100) / ((adj_str_wgt[p_ptr->stat_ind[A_STR]] * (p_ptr->pclass == CLASS_BERSERKER ? 150 : 100)) / 2));
 #endif
