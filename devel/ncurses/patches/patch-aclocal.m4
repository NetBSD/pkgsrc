$NetBSD: patch-aclocal.m4,v 1.1 2016/12/18 23:30:34 joerg Exp $

--- aclocal.m4.orig	2015-08-06 00:46:34.000000000 +0000
+++ aclocal.m4
@@ -3309,7 +3309,15 @@ CF_EOF
 		for cf_item in $cf_LIST_MODELS
 		do
 			CF_LIB_SUFFIX($cf_item,cf_suffix,cf_depsuf)
-			cf_libname=$cf_dir
+			case $cf_dir in
+			form|menu|panel)
+				cf_libname=gnu$cf_dir
+				;;
+			*)
+				cf_libname=$cf_dir
+				;;
+			esac
+			
 			test "$cf_dir" = c++ && cf_libname=ncurses++
 			if test $cf_item = shared ; then
 				if test -n "${LIB_SUFFIX}"
@@ -4250,11 +4258,7 @@ case ".$MANPAGE_RENAMES" in
 	;;
 (.|.yes)
 	# Debian 'man' program?
-	if test -f /etc/debian_version ; then
-		MANPAGE_RENAMES=`cd $srcdir && pwd`/man/man_db.renames
-	else
-		MANPAGE_RENAMES=no
-	fi
+	MANPAGE_RENAMES=no
 	;;
 esac
 
@@ -6174,8 +6178,16 @@ do
 			CF_UPPER(cf_have_include,$cf_dir)
 			AC_DEFINE_UNQUOTED(HAVE_${cf_have_include}_H)
 			AC_DEFINE_UNQUOTED(HAVE_LIB${cf_have_include})
-			TEST_DEPS="${LIB_DIR}/${LIB_PREFIX}${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEPS"
-			TEST_DEP2="${LIB_2ND}/${LIB_PREFIX}${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEP2"
+			case ${cf_dir} in
+			form|menu|panel)
+				TEST_DEPS="${LIB_DIR}/${LIB_PREFIX}gnu${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEPS"
+				TEST_DEP2="${LIB_2ND}/${LIB_PREFIX}gnu${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEP2"
+				;;
+			*)
+				TEST_DEPS="${LIB_DIR}/${LIB_PREFIX}${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEPS"
+				TEST_DEP2="${LIB_2ND}/${LIB_PREFIX}${cf_dir}${DFT_DEP_SUFFIX} $TEST_DEP2"
+				;;
+			esac
 			if test "$DFT_LWR_MODEL" = "libtool"; then
 				TEST_ARGS="${TEST_DEPS}"
 				TEST_ARG2="${TEST_DEP2}"
