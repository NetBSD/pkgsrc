$NetBSD: patch-acinclude.m4,v 1.2 2014/07/18 10:28:11 ryoon Exp $

Solaris seems to need -std=c99 with recent pkgsrc so keep it
and at the same time fix a typo involving CXXFLAGS.

--- acinclude.m4.orig	2013-09-13 21:36:38.000000000 +0000
+++ acinclude.m4
@@ -69,6 +69,7 @@ powerpc*-*-linux*)
 *-dec-osf*) icu_cv_host_frag=mh-alpha-osf ;;
 *-*-nto*)	icu_cv_host_frag=mh-qnx ;;
 *-ncr-*)	icu_cv_host_frag=mh-mpras ;;
+*-*-sco3.2v5*)	icu_cv_host_frag=mh-scoosr5 ;;
 *) 		icu_cv_host_frag=mh-unknown ;;
 esac
 		]
@@ -262,7 +263,7 @@ AC_DEFUN([AC_CHECK_64BIT_LIBS],
                     if test "$CAN_BUILD_64" != yes; then
                         # Nope. back out changes.
                         CFLAGS="${CFLAGS_OLD}"
-                        CXXFLAGS="${CFLAGS_OLD}"
+                        CXXFLAGS="${CXXFLAGS_OLD}"
                         # 2. try xarch=v9 [deprecated]
                         ## TODO: cross compile: the following won't work.
                         SPARCV9=`isainfo -n 2>&1 | grep sparcv9`
@@ -457,9 +458,6 @@ AC_DEFUN([AC_CHECK_STRICT_COMPILE],
         if test "$GCC" = yes
         then
             case "${host}" in
-            *-*-solaris*)
-                # Don't use -std=c99 option on Solaris/GCC
-                ;;
             *)
                 # Do not use -ansi. It limits us to C90, and it breaks some platforms.
                 # We use -std=c99 to disable the gnu99 defaults and its associated warnings
