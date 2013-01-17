$NetBSD: patch-hv.c,v 1.1 2013/01/17 13:29:59 manu Exp $

Work around a crash with apaache-1.3.42 and mod_perl-1.31:

Program received signal SIGSEGV, Segmentation fault.
[Switching to LWP 1]
Perl_hv_undef_flags (my_perl=0xbb537800, hv=0x0, flags=0) at hv.c:1788
1788        const bool save = !!SvREFCNT(hv);
(gdb) bt
#0  Perl_hv_undef_flags (my_perl=0xbb537800, hv=0x0, flags=0) at hv.c:1788
#1  0xbb646f8e in perl_util_cleanup () from /usr/pkg/lib/httpd/mod_perl.so
#2  0xbb639b10 in perl_shutdown () from /usr/pkg/lib/httpd/mod_perl.so
#3  0xbb639ec3 in mp_dso_unload () from /usr/pkg/lib/httpd/mod_perl.so
#4  0x08073524 in ap_clear_pool ()
#5  0x08081956 in main ()


--- hv.c.orig	2013-01-17 08:54:13.000000000 +0100
+++ hv.c	2013-01-17 08:55:42.000000000 +0100
@@ -1784,14 +1784,16 @@
 {
     dVAR;
     register XPVHV* xhv;
     const char *name;
-    const bool save = !!SvREFCNT(hv);
+    bool save;
 
     if (!hv)
 	return;
+
     DEBUG_A(Perl_hv_assert(aTHX_ hv));
     xhv = (XPVHV*)SvANY(hv);
+    save = !!SvREFCNT(hv);
 
     /* The name must be deleted before the call to hfreeeeentries so that
        CVs are anonymised properly. But the effective name must be pre-
        served until after that call (and only deleted afterwards if the
