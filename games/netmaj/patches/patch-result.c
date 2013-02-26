$NetBSD: patch-result.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- result.c.orig	2013-02-25 20:42:32.000000000 +0000
+++ result.c
@@ -33,6 +33,7 @@
 static int fu_calc_head();
 static int find_kind();
 static result_clear_genyakus();
+static void result_calc_ryukyoku(global_t *gp, result_t *yr);
 
 result_new(gp) global_t *gp; {
 	int i;
@@ -118,7 +119,7 @@ result_check_sukan(gp) global_t *gp; {
 	return (knmax==4)?0:1;
 }
 
-result_calc(gp,mode,pp,pp_num) global_t *gp; int *pp; {
+void result_calc(global_t *gp, int mode, int *pp, int pp_num) {
 	int i,ac,p;
 	result_t yr[4];
 	int st[4];
@@ -216,7 +217,7 @@ calc_tumibo(gp,yr,furi) global_t *gp; re
 	}
 }
 
-result_calc_ryukyoku(gp,yr) global_t *gp; result_t *yr; {
+static void result_calc_ryukyoku(global_t *gp, result_t *yr) {
 	int i,n;
 	int tenpai[4];
 	int tenpai_cnt=0;
