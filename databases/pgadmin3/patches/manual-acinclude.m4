$NetBSD: manual-acinclude.m4,v 1.1 2016/02/16 03:45:19 dbj Exp $

Remove code that insists wx-config is in a directory named bin

--- acinclude.m4.orig	2013-07-19 08:53:33.000000000 +0000
+++ acinclude.m4
@@ -87,15 +87,6 @@ AC_DEFUN([LOCATE_WXWIDGETS],
 		WX_CONFIG=${WX_HOME}/bin/wx-config
 	], 
 	[
-		WX_HOME=/usr/local/wx2
-		if test ! -f "${WX_HOME}/bin/wx-config"
-		then
-			WX_HOME=/usr/local
-			if test ! -f "${WX_HOME}/bin/wx-config"
-			then
-				WX_HOME=/usr
-				if test ! -f "${WX_HOME}/bin/wx-config"
-				then
 		    # Search the path
 				    AC_PATH_PROGS(WX_CONFIG, wx-config)
 		    if test ! -f "${WX_CONFIG}"
@@ -104,10 +95,6 @@ AC_DEFUN([LOCATE_WXWIDGETS],
 		    else
 					   WX_HOME=`${WX_CONFIG} --prefix`
 		    fi
-				fi
-			fi
-		fi
-		WX_CONFIG=${WX_HOME}/bin/wx-config
 	])
 ])
 
@@ -730,9 +717,8 @@ AC_SUBST(EDB_LIBPQ)
 ################################################
 AC_DEFUN([SETUP_WXWIDGETS],
 [
-	if test -n "${WX_HOME}"
+	if test -n "${WX_CONFIG}"
 	then
-		LDFLAGS="$LDFLAGS -L${WX_HOME}/lib"
 		WX_OLD_LDFLAGS="$LDFLAGS"
 		WX_OLD_CPPFLAGS="$CPPFLAGS"
 	
