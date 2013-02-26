$NetBSD: patch-analize.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- analize.c.orig	2013-02-25 20:44:13.000000000 +0000
+++ analize.c
@@ -98,7 +98,6 @@ static int pointdiff;
 
 static calc_myposition();
 static analize_policy();
-static analize_base();
 static filter_random();
 static filter_dora();
 static filter_zone();
@@ -118,6 +117,8 @@ static print_pai();
 static print_point();
 static naki_look();
 
+static void analize_base(global_t *gp, int p, int max, int *rp);
+
 static calc_myposition(gp) global_t *gp; {
         int i,j,tmp;
 	int s[4];
@@ -224,10 +225,11 @@ typedef struct {
 
 pnt_t result_pnt;
 
+void
 #ifdef INTEST
 new_analize(gp,p) global_t *gp;
 #else
-analize(gp,p) global_t *gp;
+analize(global_t *gp, int p)
 #endif
 {
 	int r[14];
@@ -608,7 +610,7 @@ static analize_policy(gp) global_t *gp; 
 }
 
 
-static analize_base(gp,p,max,rp) global_t *gp; int *rp; {
+static void analize_base(global_t *gp, int p, int max, int *rp) {
 	ahand_t a;
 	int rests[14];
 	int r[14];
