$NetBSD: patch-src_libjasper_base_jas__icc.c,v 1.2 2016/05/16 14:03:40 he Exp $

CVE-2016-1577 prevent double free. Via Debian.
CVE-2016-2116 memory leak / DoS. Via Debian.

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_icc.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/base/jas_icc.c	2016-03-31 14:48:20.000000000 +0200
@@ -300,6 +300,7 @@
 				if (jas_iccprof_setattr(prof, tagtabent->tag, attrval))
 					goto error;
 				jas_iccattrval_destroy(attrval);
+				attrval = 0;
 			} else {
 #if 0
 				jas_eprintf("warning: skipping unknown tag type\n");
@@ -373,7 +374,7 @@
 	jas_icctagtab_t *tagtab;
 
 	tagtab = &prof->tagtab;
-	if (!(tagtab->ents = jas_malloc(prof->attrtab->numattrs *
+	if (!(tagtab->ents = jas_alloc2(prof->attrtab->numattrs,
 	  sizeof(jas_icctagtabent_t))))
 		goto error;
 	tagtab->numents = prof->attrtab->numattrs;
@@ -522,7 +523,7 @@
 	}
 	if (jas_iccgetuint32(in, &tagtab->numents))
 		goto error;
-	if (!(tagtab->ents = jas_malloc(tagtab->numents *
+	if (!(tagtab->ents = jas_alloc2(tagtab->numents,
 	  sizeof(jas_icctagtabent_t))))
 		goto error;
 	tagtabent = tagtab->ents;
@@ -743,8 +744,7 @@
 {
 	jas_iccattr_t *newattrs;
 	assert(maxents >= tab->numattrs);
-	newattrs = tab->attrs ? jas_realloc(tab->attrs, maxents *
-	  sizeof(jas_iccattr_t)) : jas_malloc(maxents * sizeof(jas_iccattr_t));
+	newattrs = jas_realloc2(tab->attrs, maxents, sizeof(jas_iccattr_t));
 	if (!newattrs)
 		return -1;
 	tab->attrs = newattrs;
@@ -999,7 +999,7 @@
 
 	if (jas_iccgetuint32(in, &curv->numents))
 		goto error;
-	if (!(curv->ents = jas_malloc(curv->numents * sizeof(jas_iccuint16_t))))
+	if (!(curv->ents = jas_alloc2(curv->numents, sizeof(jas_iccuint16_t))))
 		goto error;
 	for (i = 0; i < curv->numents; ++i) {
 		if (jas_iccgetuint16(in, &curv->ents[i]))
@@ -1100,7 +1100,7 @@
 	if (jas_iccgetuint32(in, &txtdesc->uclangcode) ||
 	  jas_iccgetuint32(in, &txtdesc->uclen))
 		goto error;
-	if (!(txtdesc->ucdata = jas_malloc(txtdesc->uclen * 2)))
+	if (!(txtdesc->ucdata = jas_alloc2(txtdesc->uclen, 2)))
 		goto error;
 	if (jas_stream_read(in, txtdesc->ucdata, txtdesc->uclen * 2) !=
 	  JAS_CAST(int, txtdesc->uclen * 2))
@@ -1292,17 +1292,17 @@
 	  jas_iccgetuint16(in, &lut8->numouttabents))
 		goto error;
 	clutsize = jas_iccpowi(lut8->clutlen, lut8->numinchans) * lut8->numoutchans;
-	if (!(lut8->clut = jas_malloc(clutsize * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->intabsbuf = jas_malloc(lut8->numinchans *
-	  lut8->numintabents * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->intabs = jas_malloc(lut8->numinchans *
+	if (!(lut8->clut = jas_alloc2(clutsize, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->intabsbuf = jas_alloc3(lut8->numinchans,
+	  lut8->numintabents, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->intabs = jas_alloc2(lut8->numinchans,
 	  sizeof(jas_iccuint8_t *))))
 		goto error;
 	for (i = 0; i < lut8->numinchans; ++i)
 		lut8->intabs[i] = &lut8->intabsbuf[i * lut8->numintabents];
-	if (!(lut8->outtabsbuf = jas_malloc(lut8->numoutchans *
-	  lut8->numouttabents * sizeof(jas_iccuint8_t))) ||
-	  !(lut8->outtabs = jas_malloc(lut8->numoutchans *
+	if (!(lut8->outtabsbuf = jas_alloc3(lut8->numoutchans,
+	  lut8->numouttabents, sizeof(jas_iccuint8_t))) ||
+	  !(lut8->outtabs = jas_alloc2(lut8->numoutchans,
 	  sizeof(jas_iccuint8_t *))))
 		goto error;
 	for (i = 0; i < lut8->numoutchans; ++i)
@@ -1461,17 +1461,17 @@
 	  jas_iccgetuint16(in, &lut16->numouttabents))
 		goto error;
 	clutsize = jas_iccpowi(lut16->clutlen, lut16->numinchans) * lut16->numoutchans;
-	if (!(lut16->clut = jas_malloc(clutsize * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->intabsbuf = jas_malloc(lut16->numinchans *
-	  lut16->numintabents * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->intabs = jas_malloc(lut16->numinchans *
+	if (!(lut16->clut = jas_alloc2(clutsize, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->intabsbuf = jas_alloc3(lut16->numinchans,
+	  lut16->numintabents, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->intabs = jas_alloc2(lut16->numinchans,
 	  sizeof(jas_iccuint16_t *))))
 		goto error;
 	for (i = 0; i < lut16->numinchans; ++i)
 		lut16->intabs[i] = &lut16->intabsbuf[i * lut16->numintabents];
-	if (!(lut16->outtabsbuf = jas_malloc(lut16->numoutchans *
-	  lut16->numouttabents * sizeof(jas_iccuint16_t))) ||
-	  !(lut16->outtabs = jas_malloc(lut16->numoutchans *
+	if (!(lut16->outtabsbuf = jas_alloc3(lut16->numoutchans,
+	  lut16->numouttabents, sizeof(jas_iccuint16_t))) ||
+	  !(lut16->outtabs = jas_alloc2(lut16->numoutchans,
 	  sizeof(jas_iccuint16_t *))))
 		goto error;
 	for (i = 0; i < lut16->numoutchans; ++i)
@@ -1699,6 +1699,8 @@
 	jas_stream_close(in);
 	return prof;
 error:
+	if (in)
+		jas_stream_close(in);
 	return 0;
 }
 
