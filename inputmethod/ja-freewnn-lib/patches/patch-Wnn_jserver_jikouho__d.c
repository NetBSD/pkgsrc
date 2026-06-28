$NetBSD: patch-Wnn_jserver_jikouho__d.c,v 1.1 2026/06/28 06:16:27 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Wnn/jserver/jikouho_d.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/jikouho_d.c
@@ -60,7 +60,7 @@ static void sons_set (register struct JK
 static void dsd_hyouka (struct DSD_DBN *);
 static void cnt_sbn (register struct JKT_SBN *, register int *, register int *);
 static void cnt_dbn (register struct JKT_DBN *, register int *dbn_cnt, register int *sbn_cnt);
-static int cmp_dsd_dbn (struct DSD_DBN *, struct DSD_DBN *);
+static int cmp_dsd_dbn (const void *, const void *);
 static int jkt_dbn (int, int, int,
 #ifndef NO_FZK
 		    w_char *,
@@ -136,16 +136,18 @@ jkt_get_dai (yomi_sno, yomi_eno, beginve
         dbn->v_jc = DIVID_HYOUKA (dbn->v_jc, divid);
     }
   /* SORT */
-  qsort ((char *) *dsd_dbn, cnt, sizeof (struct DSD_DBN), cmp_dsd_dbn);
+  qsort (*dsd_dbn, cnt, sizeof (struct DSD_DBN), cmp_dsd_dbn);
   return (cnt);
 }
 
 static int
 cmp_dsd_dbn (dbn1, dbn2)
-     struct DSD_DBN *dbn1;
-     struct DSD_DBN *dbn2;
+     const void *dbn1;
+     const void *dbn2;
 {
-  return (dbn2->v_jc - dbn1->v_jc);
+  const struct DSD_DBN *p1 = dbn1;
+  const struct DSD_DBN *p2 = dbn2;
+  return (p2->v_jc - p1->v_jc);
 }
 
 static void
