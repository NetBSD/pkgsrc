$NetBSD: patch-config-scripts_cups-sharedlibs.m4,v 1.3 2017/09/03 11:30:54 leot Exp $

libtoolize.

--- config-scripts/cups-sharedlibs.m4.orig	2017-06-30 15:44:38.000000000 +0000
+++ config-scripts/cups-sharedlibs.m4
@@ -20,6 +20,24 @@ cupsbase="cups"
 LIBCUPSBASE="lib$cupsbase"
 LIBCUPSSTATIC="lib$cupsbase.a"
 
+AC_ARG_ENABLE(libtool, [  --enable-libtool[=LIBTOOL_PATH]
+			turn on building with libtool (UNSUPPORTED!), default=no])
+
+if test x$enable_libtool != xno; then
+	echo "WARNING: libtool is not supported or endorsed by Easy Software Products."
+	echo "         WE DO NOT PROVIDE TECHNICAL SUPPORT FOR LIBTOOL PROBLEMS."
+	echo "         (even if you have a support contract)"
+	enable_shared=no
+	if test x$enable_libtool = xyes; then
+		LIBTOOL=libtool
+	else
+		LIBTOOL=$enable_libtool
+	fi
+else
+	LIBTOOL=
+fi
+AC_SUBST(LIBTOOL)
+
 if test x$enable_shared != xno; then
 	case "$host_os_name" in
 		sunos*)
@@ -65,6 +83,15 @@ if test x$enable_shared != xno; then
 			DSOFLAGS="$DSOFLAGS -Wl,-soname,\`basename \$@\` -shared \$(OPTIM)"
 			;;
 	esac
+elif test x$enable_libtool != xno; then
+	LIBCUPS="libcups.la"
+	LIBCUPSCGI="libcupscgi.la"
+	LIBCUPSDRIVER="libcupsdriver.la"
+	LIBCUPSIMAGE="libcupsimage.la"
+	LIBCUPSMIME="libcupsmime.la"
+	LIBCUPSPPDC="libcupsppdc.la"
+	DSO="\$(CC)"
+	DSOXX="\$(CXX)"
 else
 	PICFLAG=0
 	LIBCUPS="lib$cupsbase.a"
@@ -88,8 +115,13 @@ AC_SUBST(LIBCUPSPPDC)
 AC_SUBST(LIBCUPSSTATIC)
 
 if test x$enable_shared = xno; then
-	LINKCUPS="../cups/lib$cupsbase.a"
-	LINKCUPSIMAGE="../filter/libcupsimage.a"
+	if test x$enable_libtool = xno; then
+		LINKCUPS="../cups/lib$cupsbase.a"
+		LINKCUPSIMAGE="../filter/libcupsimage.a"
+	else
+		LINKCUPS="../cups/\$(LIBCUPS)"
+		LINKCUPSIMAGE="../filter/\$(LIBCUPSIMAGE)"
+	fi
 
 	EXTLINKCUPS="-lcups"
 	EXTLINKCUPSIMAGE="-lcupsimage"
@@ -117,10 +149,11 @@ if test "$DSO" != ":"; then
 	DSOLIBS="\$(LIBZ)"
 	IMGLIBS=""
 
-	# Tell the run-time linkers where to find a DSO.  Some platforms
-	# need this option, even when the library is installed in a
-	# standard location...
-	case $host_os_name in
+	if test x$enable_libtool = xno; then
+		# Tell the run-time linkers where to find a DSO.  Some platforms
+		# need this option, even when the library is installed in a
+		# standard location...
+		case $host_os_name in
                 sunos*)
                 	# Solaris...
 			if test $exec_prefix != /usr; then
@@ -145,7 +178,8 @@ if test "$DSO" != ":"; then
 				EXPORT_LDFLAGS="-Wl,-rpath,$libdir"
 			fi
 			;;
-	esac
+		esac
+	fi
 else
 	DSOLIBS=""
 	IMGLIBS="\$(LIBZ)"
