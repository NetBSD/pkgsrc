$NetBSD: patch-hv.c,v 1.2 2013/05/31 10:55:15 adam Exp $

Work around a crash with apaache-1.3.42 and mod_perl-1.31:

--- hv.c.orig	2013-05-09 13:47:39.000000000 +0000
+++ hv.c
@@ -1728,12 +1728,13 @@ Perl_hv_undef_flags(pTHX_ HV *hv, U32 fl
     dVAR;
     XPVHV* xhv;
     const char *name;
-    const bool save = !!SvREFCNT(hv);
+    bool save;
 
     if (!hv)
 	return;
     DEBUG_A(Perl_hv_assert(aTHX_ hv));
     xhv = (XPVHV*)SvANY(hv);
+    save = !!SvREFCNT(hv);
 
     /* The name must be deleted before the call to hfreeeeentries so that
        CVs are anonymised properly. But the effective name must be pre-
