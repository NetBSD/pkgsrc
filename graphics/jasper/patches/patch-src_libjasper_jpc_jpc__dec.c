$NetBSD$

Apply fixes from
http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=469786
and
https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-9029

Also add a patch from Debian (bug #413041) to fix some heap corruption
on malformed image input (CVE-2007-2721),

Apply fix for CVE-2014-8157, taken from
https://bugzilla.redhat.com/show_bug.cgi?id=1179282

--- src/libjasper/jpc/jpc_dec.c.orig	2014-12-05 12:10:45.000000000 +0000
+++ src/libjasper/jpc/jpc_dec.c
@@ -489,7 +489,7 @@ static int jpc_dec_process_sot(jpc_dec_t
 		dec->curtileendoff = 0;
 	}
 
-	if (JAS_CAST(int, sot->tileno) > dec->numtiles) {
+	if (JAS_CAST(int, sot->tileno) >= dec->numtiles) {
 		jas_eprintf("invalid tile number in SOT marker segment\n");
 		return -1;
 	}
@@ -1069,12 +1069,12 @@ static int jpc_dec_tiledecode(jpc_dec_t 
 	/* Apply an inverse intercomponent transform if necessary. */
 	switch (tile->cp->mctid) {
 	case JPC_MCT_RCT:
-		assert(dec->numcomps == 3);
+		assert(dec->numcomps >= 3);
 		jpc_irct(tile->tcomps[0].data, tile->tcomps[1].data,
 		  tile->tcomps[2].data);
 		break;
 	case JPC_MCT_ICT:
-		assert(dec->numcomps == 3);
+		assert(dec->numcomps >= 3);
 		jpc_iict(tile->tcomps[0].data, tile->tcomps[1].data,
 		  tile->tcomps[2].data);
 		break;
@@ -1234,6 +1234,7 @@ static int jpc_dec_process_siz(jpc_dec_t
 		}
 		for (compno = 0, cmpt = dec->cmpts, tcomp = tile->tcomps;
 		  compno < dec->numcomps; ++compno, ++cmpt, ++tcomp) {
+			tcomp->numrlvls = 0;
 			tcomp->rlvls = 0;
 			tcomp->data = 0;
 			tcomp->xstart = JPC_CEILDIV(tile->xstart, cmpt->hstep);
@@ -1280,7 +1281,7 @@ static int jpc_dec_process_coc(jpc_dec_t
 	jpc_coc_t *coc = &ms->parms.coc;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, coc->compno) > dec->numcomps) {
+	if (JAS_CAST(int, coc->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in COC marker segment\n");
 		return -1;
 	}
@@ -1306,7 +1307,7 @@ static int jpc_dec_process_rgn(jpc_dec_t
 	jpc_rgn_t *rgn = &ms->parms.rgn;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, rgn->compno) > dec->numcomps) {
+	if (JAS_CAST(int, rgn->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in RGN marker segment\n");
 		return -1;
 	}
@@ -1355,7 +1356,7 @@ static int jpc_dec_process_qcc(jpc_dec_t
 	jpc_qcc_t *qcc = &ms->parms.qcc;
 	jpc_dec_tile_t *tile;
 
-	if (JAS_CAST(int, qcc->compno) > dec->numcomps) {
+	if (JAS_CAST(int, qcc->compno) >= dec->numcomps) {
 		jas_eprintf("invalid component number in QCC marker segment\n");
 		return -1;
 	}
@@ -1466,7 +1467,9 @@ static int jpc_dec_process_unk(jpc_dec_t
 	dec = 0;
 
 	jas_eprintf("warning: ignoring unknown marker segment\n");
-	jpc_ms_dump(ms, stderr);
+	if (jas_getdbglevel() >= 1) {
+		jpc_ms_dump(ms, stderr);
+	}
 	return 0;
 }
 
