$NetBSD: patch-src_libjasper_jpc_jpc__t2enc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/jpc/jpc_t2enc.c.orig	2007-01-19 21:43:07.000000000 +0000
+++ src/libjasper/jpc/jpc_t2enc.c
@@ -565,7 +565,7 @@ jpc_pi_t *jpc_enc_pi_create(jpc_enc_cp_t
 	}
 	pi->pktno = -1;
 	pi->numcomps = cp->numcmpts;
-	if (!(pi->picomps = jas_malloc(pi->numcomps * sizeof(jpc_picomp_t)))) {
+	if (!(pi->picomps = jas_alloc2(pi->numcomps, sizeof(jpc_picomp_t)))) {
 		jpc_pi_destroy(pi);
 		return 0;
 	}
@@ -577,7 +577,7 @@ jpc_pi_t *jpc_enc_pi_create(jpc_enc_cp_t
 	for (compno = 0, tcomp = tile->tcmpts, picomp = pi->picomps;
 	  compno < pi->numcomps; ++compno, ++tcomp, ++picomp) {
 		picomp->numrlvls = tcomp->numrlvls;
-		if (!(picomp->pirlvls = jas_malloc(picomp->numrlvls *
+		if (!(picomp->pirlvls = jas_alloc2(picomp->numrlvls,
 		  sizeof(jpc_pirlvl_t)))) {
 			jpc_pi_destroy(pi);
 			return 0;
@@ -591,7 +591,7 @@ jpc_pi_t *jpc_enc_pi_create(jpc_enc_cp_t
 /* XXX sizeof(long) should be sizeof different type */
 			pirlvl->numprcs = rlvl->numprcs;
 			if (rlvl->numprcs) {
-				if (!(pirlvl->prclyrnos = jas_malloc(pirlvl->numprcs *
+				if (!(pirlvl->prclyrnos = jas_alloc2(pirlvl->numprcs,
 				  sizeof(long)))) {
 					jpc_pi_destroy(pi);
 					return 0;
