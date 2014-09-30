$NetBSD: patch-dist_Data-Dumper_Dumper.xs,v 1.1.2.2 2014/09/30 17:03:04 tron Exp $

patch for CVE-2014-4330, remove for 5.20.1
taken from http://perl5.git.perl.org/perl.git/commitdiff/19be3be6968e2337bcdfe480693fff795ecd1304

--- dist/Data-Dumper/Dumper.xs.orig	2014-05-26 13:34:19.000000000 +0000
+++ dist/Data-Dumper/Dumper.xs
@@ -28,7 +28,7 @@ static I32 DD_dump (pTHX_ SV *val, const
 		    SV *pad, SV *xpad, SV *apad, SV *sep, SV *pair,
 		    SV *freezer, SV *toaster,
 		    I32 purity, I32 deepcopy, I32 quotekeys, SV *bless,
-		    I32 maxdepth, SV *sortkeys, int use_sparse_seen_hash, I32 useqq);
+		    I32 maxdepth, SV *sortkeys, int use_sparse_seen_hash, I32 useqq, IV maxrecurse);
 
 #ifndef HvNAME_get
 #define HvNAME_get HvNAME
@@ -412,7 +412,7 @@ DD_dump(pTHX_ SV *val, const char *name,
 	AV *postav, I32 *levelp, I32 indent, SV *pad, SV *xpad,
 	SV *apad, SV *sep, SV *pair, SV *freezer, SV *toaster, I32 purity,
 	I32 deepcopy, I32 quotekeys, SV *bless, I32 maxdepth, SV *sortkeys,
-        int use_sparse_seen_hash, I32 useqq)
+        int use_sparse_seen_hash, I32 useqq, IV maxrecurse)
 {
     char tmpbuf[128];
     Size_t i;
@@ -589,6 +589,10 @@ DD_dump(pTHX_ SV *val, const char *name,
 	    return 1;
 	}
 
+	if (maxrecurse > 0 && *levelp >= maxrecurse) {
+	    croak("Recursion limit of %" IVdf " exceeded", maxrecurse);
+	}
+
 	if (realpack && !no_bless) {				/* we have a blessed ref */
 	    STRLEN blesslen;
 	    const char * const blessstr = SvPV(bless, blesslen);
@@ -674,7 +678,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 		DD_dump(aTHX_ ival, SvPVX_const(namesv), SvCUR(namesv), retval, seenhv,
 			postav, levelp,	indent, pad, xpad, apad, sep, pair,
 			freezer, toaster, purity, deepcopy, quotekeys, bless,
-			maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+			maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+			maxrecurse);
 		sv_catpvn(retval, ")}", 2);
 	    }						     /* plain */
 	    else {
@@ -682,7 +687,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 		DD_dump(aTHX_ ival, SvPVX_const(namesv), SvCUR(namesv), retval, seenhv,
 			postav, levelp,	indent, pad, xpad, apad, sep, pair,
 			freezer, toaster, purity, deepcopy, quotekeys, bless,
-			maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+			maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+			maxrecurse);
 	    }
 	    SvREFCNT_dec(namesv);
 	}
@@ -694,7 +700,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 	    DD_dump(aTHX_ ival, SvPVX_const(namesv), SvCUR(namesv), retval, seenhv,
 		    postav, levelp,	indent, pad, xpad, apad, sep, pair,
 		    freezer, toaster, purity, deepcopy, quotekeys, bless,
-		    maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+		    maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+		    maxrecurse);
 	    SvREFCNT_dec(namesv);
 	}
 	else if (realtype == SVt_PVAV) {
@@ -767,7 +774,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 		DD_dump(aTHX_ elem, iname, ilen, retval, seenhv, postav,
 			levelp,	indent, pad, xpad, apad, sep, pair,
 			freezer, toaster, purity, deepcopy, quotekeys, bless,
-			maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+			maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+			maxrecurse);
 		if (ix < ixmax)
 		    sv_catpvn(retval, ",", 1);
 	    }
@@ -970,7 +978,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 		DD_dump(aTHX_ hval, SvPVX_const(sname), SvCUR(sname), retval, seenhv,
 			postav, levelp,	indent, pad, xpad, newapad, sep, pair,
 			freezer, toaster, purity, deepcopy, quotekeys, bless,
-			maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+			maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+			maxrecurse);
 		SvREFCNT_dec(sname);
 		Safefree(nkey_buffer);
 		if (indent >= 2)
@@ -1179,7 +1188,8 @@ DD_dump(pTHX_ SV *val, const char *name,
 				seenhv, postav, &nlevel, indent, pad, xpad,
 				newapad, sep, pair, freezer, toaster, purity,
 				deepcopy, quotekeys, bless, maxdepth, 
-				sortkeys, use_sparse_seen_hash, useqq);
+				sortkeys, use_sparse_seen_hash, useqq,
+				maxrecurse);
 			SvREFCNT_dec(e);
 		    }
 		}
@@ -1269,6 +1279,7 @@ Data_Dumper_Dumpxs(href, ...)
 	    SV *val, *name, *pad, *xpad, *apad, *sep, *pair, *varname;
 	    SV *freezer, *toaster, *bless, *sortkeys;
 	    I32 purity, deepcopy, quotekeys, maxdepth = 0;
+	    IV maxrecurse = 1000;
 	    char tmpbuf[1024];
 	    I32 gimme = GIMME;
             int use_sparse_seen_hash = 0;
@@ -1355,6 +1366,8 @@ Data_Dumper_Dumpxs(href, ...)
 		    bless = *svp;
 		if ((svp = hv_fetch(hv, "maxdepth", 8, FALSE)))
 		    maxdepth = SvIV(*svp);
+		if ((svp = hv_fetch(hv, "maxrecurse", 10, FALSE)))
+		    maxrecurse = SvIV(*svp);
 		if ((svp = hv_fetch(hv, "sortkeys", 8, FALSE))) {
 		    sortkeys = *svp;
 		    if (! SvTRUE(sortkeys))
@@ -1434,7 +1447,8 @@ Data_Dumper_Dumpxs(href, ...)
 		    DD_dump(aTHX_ val, SvPVX_const(name), SvCUR(name), valstr, seenhv,
 			    postav, &level, indent, pad, xpad, newapad, sep, pair,
 			    freezer, toaster, purity, deepcopy, quotekeys,
-			    bless, maxdepth, sortkeys, use_sparse_seen_hash, useqq);
+			    bless, maxdepth, sortkeys, use_sparse_seen_hash, useqq,
+			    maxrecurse);
 		    SPAGAIN;
 		
 		    if (indent >= 2 && !terse)
