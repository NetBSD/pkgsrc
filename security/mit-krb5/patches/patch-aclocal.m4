$NetBSD: patch-aclocal.m4,v 1.2 2019/07/12 15:40:55 jperkin Exp $

Don't make sunpro warnings into errors (warnings are seen in gcc too)
Add --enable-pkgsrc-libtool option

--- aclocal.m4.orig	2018-05-03 14:34:47.000000000 +0000
+++ aclocal.m4
@@ -633,7 +633,7 @@ else
     if test "x$krb5_ac_warn_cflags_set" = xset ; then
       AC_MSG_NOTICE(not adding extra warning flags because WARN_CFLAGS was set)
     else
-      WARN_CFLAGS="-errtags=yes -errwarn=E_BAD_PTR_INT_COMBINATION,E_BAD_PTR_INT_COMB_ARG,E_PTR_TO_VOID_IN_ARITHMETIC,E_NO_IMPLICIT_DECL_ALLOWED,E_ATTRIBUTE_PARAM_UNDEFINED"
+      WARN_CFLAGS="-errtags=yes"
     fi
     if test "x$krb5_ac_warn_cxxflags_set" = xset ; then
       AC_MSG_NOTICE(not adding extra warning flags because WARN_CXXFLAGS was set)
@@ -1068,6 +1068,9 @@ AC_SUBST(SHLIBVEXT)
 AC_SUBST(SHLIBSEXT)
 AC_SUBST(DEPLIBEXT)
 AC_SUBST(PFLIBEXT)
+AC_SUBST(LALIBEXT)
+AC_SUBST(LALIB_EXPFLAGS)
+AC_SUBST(LIBTOOL_TAIL)
 AC_SUBST(LIBINSTLIST)
 AC_SUBST(DYNOBJEXT)
 AC_SUBST(MAKE_DYNOBJ_COMMAND)
@@ -1085,6 +1088,7 @@ AC_SUBST(OBJLISTS)
 AC_SUBST(STOBJEXT)
 AC_SUBST(SHOBJEXT)
 AC_SUBST(PFOBJEXT)
+AC_SUBST(LAOBJEXT)
 AC_SUBST(PICFLAGS)
 AC_SUBST(PROFFLAGS)])
 
@@ -1199,11 +1203,42 @@ else
 	KDB5_PLUGIN_DEPLIBS=
 	KDB5_PLUGIN_LIBS=
 fi
+DEPSTLIBEXT=$STLIBEXT
+AC_SUBST(DEPSTLIBEXT)
 CC_LINK="$CC_LINK_SHARED"
 CXX_LINK="$CXX_LINK_SHARED"
 
+# Check whether to build libtool archives.
+AC_ARG_ENABLE([pkgsrc-libtool],
+[  --enable-pkgsrc-libtool build libtool archives],
+[
+	case $enableval in
+	/*)	LIBTOOL=$enableval ;;
+	*)	LIBTOOL=libtool ;;
+	esac
+	AC_MSG_RESULT([Enabling libtool archives.])
+	LIBLIST='lib$(LIBBASE)$(LALIBEXT)'
+	LIBLINKS='$(TOPLIBD)/lib$(LIBBASE)$(LALIBEXT)'
+	OBJLISTS=OBJS.LA
+	LIBINSTLIST=install-libtool
+	DEPLIBEXT=$LALIBEXT
+	DEPSTLIBEXT=$LALIBEXT
+	PLUGIN='$(LIBBASE)$(LALIBEXT)'
+	PLUGININST=install-libtool
+	CC_LINK="$CC_LINK_LIBTOOL"
+	INSTALL_LIBTOOL='$(LIBTOOL) --mode=install'
+	if test "$krb5_force_static" = yes; then
+		LIBTOOL_TAIL=
+	fi
+], [
+	LIBTOOL=:
+	INSTALL_LIBTOOL=
+])
+AC_SUBST(LIBTOOL)
+AC_SUBST(INSTALL_LIBTOOL)
+
 if test -z "$LIBLIST"; then
-	AC_MSG_ERROR([must enable one of shared or static libraries])
+	AC_MSG_ERROR([must enable one of shared, libtool or static libraries])
 fi
 
 # Check whether to build profiled libraries.
