$NetBSD: patch-m4_acinclude.m4,v 1.5 2022/10/24 18:02:19 adam Exp $

we pass and assume a given MACHINE_GNU_PLATFORM, but this package did not
use this value due to an error.
the guess it had for linux (x86_64-unknown-linux-gnu), seems to trample
over our own tools:
https://mail-index.netbsd.org/pkgsrc-users/2014/03/26/msg019464.html

Do not look for qcollectiongenerator; it is now part of qhelpgenerator.

On Darwin, do not produce a mach-o bundle.

--- m4/acinclude.m4.orig	2022-07-28 13:08:26.000000000 +0000
+++ m4/acinclude.m4
@@ -37,7 +37,7 @@ AC_DEFUN([OCTAVE_CANONICAL_HOST], [
     host=unknown-unknown-unknown
     AC_MSG_WARN([configuring Octave for unknown system type])
   fi
-  canonical_host_type=$host
+  canonical_host_type=$host_alias
   AC_SUBST(canonical_host_type)
   if test -z "$host_cpu"; then
     host_cpu=unknown
@@ -2200,11 +2200,10 @@ AC_DEFUN([OCTAVE_CHECK_QT_VERSION], [AC_
     OCTAVE_CHECK_QT_TOOL([uic])
     OCTAVE_CHECK_QT_TOOL([rcc])
     OCTAVE_CHECK_QT_TOOL([lrelease])
-    OCTAVE_CHECK_QT_TOOL([qcollectiongenerator])
     OCTAVE_CHECK_QT_TOOL([qhelpgenerator])
 
     if test -n "$QT_TOOLS_MISSING"; then
-      warn_qt_tools="one or more of the Qt utilities moc, uic, rcc, lrelease, qcollectiongenerator, and qhelpgenerator not found; disabling Qt GUI"
+      warn_qt_tools="one or more of the Qt utilities moc, uic, rcc, lrelease, and qhelpgenerator not found; disabling Qt GUI"
       build_qt_gui=no
       MOC_QTVER=
       UIC_QTVER=
@@ -2731,10 +2730,8 @@ AC_DEFUN_ONCE([OCTAVE_DEFINE_MKOCTFILE_D
       SH_LDFLAGS="-shared -Wl,-expect_unresolved -Wl,'*'"
     ;;
     *-*-darwin*)
-      DL_LDFLAGS="-bundle -undefined dynamic_lookup -bind_at_load -bundle_loader ${ac_top_build_prefix}src/octave${EXEEXT} ${LDFLAGS}"
       dnl Contains variables that are defined and undefined at this point, so use
       dnl appropriate quoting to defer expansion of ${bindir} and ${version}.
-      MKOCTFILE_DL_LDFLAGS='-bundle -undefined dynamic_lookup -bind_at_load -bundle_loader ${bindir}/octave-${version}'"${EXEEXT}"
       SH_LDFLAGS="-dynamiclib -single_module ${LDFLAGS}"
       case $canonical_host_type in
         powerpc-*)
