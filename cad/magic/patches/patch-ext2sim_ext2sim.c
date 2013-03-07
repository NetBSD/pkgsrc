$NetBSD: patch-ext2sim_ext2sim.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- ext2sim/ext2sim.c.orig	2013-03-02 22:16:49.000000000 +0000
+++ ext2sim/ext2sim.c
@@ -171,6 +171,11 @@ devMerge *devMergeList = NULL ;
 /* Forward declaration */
 int _ext2sim_start();
 
+static void
+simdevOutNode(HierName *prefix, HierName *suffix, char *name, FILE *outf);
+static void
+simdevSubstrate( HierName *prefix, HierName *suffix, int type, int scale, bool doAP, FILE *outf);
+
 /*
  * ----------------------------------------------------------------------------
  *
@@ -1161,13 +1166,8 @@ simdevVisit(dev, hierName, trans)
     return 0;
 }
 
-int
-simdevSubstrate( prefix, suffix, type, scale, doAP, outf)
-HierName *prefix;
-HierName *suffix;
-int type, scale;
-bool doAP;
-FILE *outf;
+static void
+simdevSubstrate( HierName *prefix, HierName *suffix, int type, int scale, bool doAP, FILE *outf)
 {
     HashEntry *he;
     EFNodeName *nn;
@@ -1305,12 +1305,8 @@ bool simnAPHier(dterm, hierName, resClas
  * ----------------------------------------------------------------------------
  */
 
-int
-simdevOutNode(prefix, suffix, name, outf)
-    HierName *prefix;
-    HierName *suffix;
-    char *name;
-    FILE *outf;
+static void
+simdevOutNode(HierName *prefix, HierName *suffix, char *name, FILE *outf)
 {
     HashEntry *he;
     EFNodeName *nn;
