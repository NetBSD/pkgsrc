$NetBSD: patch-acinclude.m4,v 1.6 2026/11/11 11:47:11 wiz Exp $

Solaris seems to need -std=c99 with recent pkgsrc so keep it.

--- acinclude.m4.orig	2026-10-22 15:02:04.000000000 +0000
+++ acinclude.m4
@@ -85,6 +85,7 @@ powerpc*-apple-darwin*)	icu_cv_host_frag=mh-darwin-ppc
 *-dec-osf*) icu_cv_host_frag=mh-alpha-osf ;;
 *-*-nto*)	icu_cv_host_frag=mh-qnx ;;
 *-ncr-*)	icu_cv_host_frag=mh-mpras ;;
+*-*-sco3.2v5*)	icu_cv_host_frag=mh-scoosr5 ;;
 *-wasi*)	icu_cv_host_frag=mh-wasi ;;
 *) 		icu_cv_host_frag=mh-unknown ;;
 esac
