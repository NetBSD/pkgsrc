$NetBSD: patch-acinclude.m4,v 1.5 2025/03/30 21:10:47 wiz Exp $

Solaris seems to need -std=c99 with recent pkgsrc so keep it.

--- acinclude.m4.orig	Fri Mar 27 21:17:48 2015
+++ acinclude.m4
@@ -82,6 +82,7 @@ x86_64-*-cygwin) 
 *-dec-osf*) icu_cv_host_frag=mh-alpha-osf ;;
 *-*-nto*)	icu_cv_host_frag=mh-qnx ;;
 *-ncr-*)	icu_cv_host_frag=mh-mpras ;;
+*-*-sco3.2v5*)	icu_cv_host_frag=mh-scoosr5 ;;
 *) 		icu_cv_host_frag=mh-unknown ;;
 esac
 		]
