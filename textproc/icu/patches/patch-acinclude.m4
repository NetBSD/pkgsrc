$NetBSD: patch-acinclude.m4,v 1.4 2015/08/31 15:26:19 sevan Exp $

Solaris seems to need -std=c99 with recent pkgsrc so keep it.
Add support for Bitrig.

--- acinclude.m4.orig	Fri Mar 27 21:17:48 2015
+++ acinclude.m4
@@ -57,7 +57,7 @@ x86_64-*-cygwin) 
 		*-*-cygwin) icu_cv_host_frag=mh-cygwin-msvc ;;
 		esac
 	fi ;;
-*-*-*bsd*|*-*-dragonfly*) 	icu_cv_host_frag=mh-bsd-gcc ;;
+*-*-*bsd*|*-*-dragonfly*|*-*-bitrig*) 	icu_cv_host_frag=mh-bsd-gcc ;;
 *-*-aix*)
 	if test "$GCC" = yes; then
 		icu_cv_host_frag=mh-aix-gcc
@@ -82,6 +82,7 @@ x86_64-*-cygwin) 
 *-dec-osf*) icu_cv_host_frag=mh-alpha-osf ;;
 *-*-nto*)	icu_cv_host_frag=mh-qnx ;;
 *-ncr-*)	icu_cv_host_frag=mh-mpras ;;
+*-*-sco3.2v5*)	icu_cv_host_frag=mh-scoosr5 ;;
 *) 		icu_cv_host_frag=mh-unknown ;;
 esac
 		]
