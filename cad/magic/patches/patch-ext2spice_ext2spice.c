$NetBSD: patch-ext2spice_ext2spice.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- ext2spice/ext2spice.c.orig	2013-03-02 22:14:04.000000000 +0000
+++ ext2spice/ext2spice.c
@@ -223,6 +223,8 @@ devMerge *devMergeList = NULL ;
 
 
 void topVisit();
+void spcnAP(EFNode *node, int resClass, int scale, char *sterm, float m, FILE *outf, int w);
+void spcdevOutNode(HierName *prefix, HierName *suffix, char *name, FILE *outf);
 
 #ifdef MAGIC_WRAPPER
 
@@ -2084,13 +2086,7 @@ FILE *outf;
  *
  * ----------------------------------------------------------------------------
  */
-int spcnAP(node, resClass, scale, sterm, m, outf, w)
-    EFNode *node;
-    int  resClass, scale;
-    char *sterm;
-    float m;
-    FILE *outf;
-    int w;
+void spcnAP(EFNode *node, int resClass, int scale, char *sterm, float m, FILE *outf, int w)
 {
 	char fmt[30];
 	float dsc ;
@@ -2191,12 +2187,8 @@ int spcnAPHier(dterm, hierName, resClass
  * ----------------------------------------------------------------------------
  */
 
-int
-spcdevOutNode(prefix, suffix, name, outf)
-    HierName *prefix;
-    HierName *suffix;
-    char *name;
-    FILE *outf;
+void
+spcdevOutNode(HierName *prefix, HierName *suffix, char *name, FILE *outf)
 {
     HashEntry *he;
     EFNodeName *nn;
