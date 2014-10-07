$NetBSD: patch-acinclude.m4,v 1.3 2014/10/07 16:09:53 adam Exp $

Solaris seems to need -std=c99 with recent pkgsrc so keep it.

--- acinclude.m4.orig	2014-10-03 16:18:36.000000000 +0000
+++ acinclude.m4
@@ -82,6 +82,7 @@ x86_64-*-cygwin) 
 *-dec-osf*) icu_cv_host_frag=mh-alpha-osf ;;
 *-*-nto*)	icu_cv_host_frag=mh-qnx ;;
 *-ncr-*)	icu_cv_host_frag=mh-mpras ;;
+*-*-sco3.2v5*)	icu_cv_host_frag=mh-scoosr5 ;;
 *) 		icu_cv_host_frag=mh-unknown ;;
 esac
 		]
