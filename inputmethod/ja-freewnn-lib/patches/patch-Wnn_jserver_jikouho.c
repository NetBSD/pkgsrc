$NetBSD: patch-Wnn_jserver_jikouho.c,v 1.1 2026/06/28 06:16:27 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Wnn/jserver/jikouho.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jserver/jikouho.c
@@ -49,7 +49,7 @@
 #include        "kaiseki.h"
 
 static struct JKT_SBN *find_jktsbn (struct JKT_SBN **, struct JKT_SONE *, int, int j_c);
-static int cmp_dsd_sbn (struct DSD_SBN *, struct DSD_SBN *);
+static int cmp_dsd_sbn (const void *, const void *);
 static int cnt_jkt_sbn (register struct JKT_SBN *sbn);
 static int get_suuji_kouho (register struct JKT_SBN *);
 static int get_eisuu_kouho (struct JKT_SBN *);
@@ -471,16 +471,18 @@ jkt_get_syo (yomi_sno, yomi_eno, beginve
       freejktsbn (jktsbn);
       jktsbn = next_sbn;
     }
-  qsort ((char *) *dsd_sbn, cnt, sizeof (struct DSD_SBN), cmp_dsd_sbn);
+  qsort (*dsd_sbn, cnt, sizeof (struct DSD_SBN), cmp_dsd_sbn);
   return (cnt);
 }
 
 static int
 cmp_dsd_sbn (sbn1, sbn2)
-     struct DSD_SBN *sbn1;
-     struct DSD_SBN *sbn2;
+     const void *sbn1;
+     const void *sbn2;
 {
-  return (sbn2->v_jc - sbn1->v_jc);
+  const struct DSD_SBN *p1 = sbn1;
+  const struct DSD_SBN *p2 = sbn2;
+  return (p2->v_jc - p1->v_jc);
 }
 
 static int
