$NetBSD: patch-mozilla_build_autoconf_nss.m4,v 1.1.1.1 2012/03/15 09:45:29 ryoon Exp $

--- mozilla/build/autoconf/nss.m4.orig	2012-02-16 10:24:47.000000000 +0000
+++ mozilla/build/autoconf/nss.m4
@@ -22,18 +22,18 @@ AC_ARG_WITH(nss-exec-prefix,
 	if test -n "$nss_config_exec_prefix"; then
 		nss_config_args="$nss_config_args --exec-prefix=$nss_config_exec_prefix"
 		if test -z "$NSS_CONFIG"; then
-			NSS_CONFIG=$nss_config_exec_prefix/bin/nss-config
+			NSS_CONFIG=$nss_config_exec_prefix/bin/pkg-config
 		fi
 	fi
 	if test -n "$nss_config_prefix"; then
 		nss_config_args="$nss_config_args --prefix=$nss_config_prefix"
 		if test -z "$NSS_CONFIG"; then
-			NSS_CONFIG=$nss_config_prefix/bin/nss-config
+			NSS_CONFIG=$nss_config_prefix/bin/pkg-config
 		fi
 	fi
 
 	unset ac_cv_path_NSS_CONFIG
-	AC_PATH_PROG(NSS_CONFIG, nss-config, no)
+	AC_PATH_PROG(NSS_CONFIG, pkg-config, no)
 	min_nss_version=ifelse([$1], ,3.0.0,$1)
 	AC_MSG_CHECKING(for NSS - version >= $min_nss_version)
 
@@ -41,14 +41,14 @@ AC_ARG_WITH(nss-exec-prefix,
 	if test "$NSS_CONFIG" = "no"; then
 		no_nss="yes"
 	else
-		NSS_CFLAGS=`$NSS_CONFIG $nss_config_args --cflags`
-		NSS_LIBS=`$NSS_CONFIG $nss_config_args --libs`
+		NSS_CFLAGS=`$NSS_CONFIG $nss_config_args nss --cflags`
+		NSS_LIBS=`$NSS_CONFIG $nss_config_args nss --libs`
 
-		nss_config_major_version=`$NSS_CONFIG $nss_config_args --version | \
+		nss_config_major_version=`$NSS_CONFIG $nss_config_args nss --modversion | \
 			sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
-		nss_config_minor_version=`$NSS_CONFIG $nss_config_args --version | \
+		nss_config_minor_version=`$NSS_CONFIG $nss_config_args nss --modversion | \
 			sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
-		nss_config_micro_version=`$NSS_CONFIG $nss_config_args --version | \
+		nss_config_micro_version=`$NSS_CONFIG $nss_config_args nss --modversion | \
 			sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
 		min_nss_major_version=`echo $min_nss_version | \
 			sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
