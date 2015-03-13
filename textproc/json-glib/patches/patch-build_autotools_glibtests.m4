$NetBSD: patch-build_autotools_glibtests.m4,v 1.2 2015/03/13 11:21:39 prlw1 Exp $

* test(1) portability fix
  https://bugzilla.gnome.org/show_bug.cgi?id=746143

--- build/autotools/glibtests.m4.orig	2013-11-22 17:36:08.000000000 +0000
+++ build/autotools/glibtests.m4
@@ -21,7 +21,7 @@ AC_DEFUN([GLIB_TESTS],
                   *) AC_MSG_ERROR([bad value ${enableval} for --enable-always-build-tests]) ;;
                  esac])
   AM_CONDITIONAL([ENABLE_ALWAYS_BUILD_TESTS], test "$ENABLE_ALWAYS_BUILD_TESTS" = "1")
-  if test "$ENABLE_INSTALLED_TESTS" == "1"; then
+  if test "$ENABLE_INSTALLED_TESTS" = "1"; then
     AC_SUBST(installed_test_metadir, [${datadir}/installed-tests/]AC_PACKAGE_NAME)
     AC_SUBST(installed_testdir, [${libexecdir}/installed-tests/]AC_PACKAGE_NAME)
   fi
