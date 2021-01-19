$NetBSD: patch-aclocal.m4,v 1.3 2021/01/19 16:18:03 brook Exp $

Don't make sunpro warnings into errors (warnings are seen in gcc too)
Add --enable-pkgsrc-libtool option

Mainline autoconf generates no shell code for AC_CONFIG_AUX_DIR().
Call it unconditionally to avoid a syntax error.  See
https://github.com/krb5/krb5/commit/f78edbe30816f049e1360cb6e203fabfdf7b98df.

--- aclocal.m4.orig	2020-05-22 00:21:40.000000000 +0000
+++ aclocal.m4
@@ -13,11 +13,7 @@ fi
 ac_topdir=$srcdir/$ac_reltopdir
 ac_config_fragdir=$ac_reltopdir/config
 # echo "Looking for $srcdir/$ac_config_fragdir"
-if test -d "$srcdir/$ac_config_fragdir"; then
-  AC_CONFIG_AUX_DIR(K5_TOPDIR/config)
-else
-  AC_MSG_ERROR([can not find config/ directory in $ac_reltopdir])
-fi
+AC_CONFIG_AUX_DIR(K5_TOPDIR/config)
 ])dnl
 dnl
 dnl Version info.
@@ -631,7 +627,7 @@ else
     if test "x$krb5_ac_warn_cflags_set" = xset ; then
       AC_MSG_NOTICE(not adding extra warning flags because WARN_CFLAGS was set)
     else
-      WARN_CFLAGS="-errtags=yes -errwarn=E_BAD_PTR_INT_COMBINATION,E_BAD_PTR_INT_COMB_ARG,E_PTR_TO_VOID_IN_ARITHMETIC,E_NO_IMPLICIT_DECL_ALLOWED,E_ATTRIBUTE_PARAM_UNDEFINED"
+      WARN_CFLAGS="-errtags=yes"
     fi
     if test "x$krb5_ac_warn_cxxflags_set" = xset ; then
       AC_MSG_NOTICE(not adding extra warning flags because WARN_CXXFLAGS was set)
@@ -1066,6 +1062,9 @@ AC_SUBST(SHLIBVEXT)
 AC_SUBST(SHLIBSEXT)
 AC_SUBST(DEPLIBEXT)
 AC_SUBST(PFLIBEXT)
+AC_SUBST(LALIBEXT)
+AC_SUBST(LALIB_EXPFLAGS)
+AC_SUBST(LIBTOOL_TAIL)
 AC_SUBST(LIBINSTLIST)
 AC_SUBST(DYNOBJEXT)
 AC_SUBST(MAKE_DYNOBJ_COMMAND)
@@ -1083,6 +1082,7 @@ AC_SUBST(OBJLISTS)
 AC_SUBST(STOBJEXT)
 AC_SUBST(SHOBJEXT)
 AC_SUBST(PFOBJEXT)
+AC_SUBST(LAOBJEXT)
 AC_SUBST(PICFLAGS)
 AC_SUBST(PROFFLAGS)])
 
@@ -1197,11 +1197,42 @@ else
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
