$NetBSD: patch-config-scripts_cups-sharedlibs.m4,v 1.1 2015/01/02 02:03:42 christos Exp $

libtoolize.

--- config-scripts/cups-sharedlibs.m4.orig	2013-10-18 16:36:01.000000000 -0400
+++ config-scripts/cups-sharedlibs.m4	2014-12-24 14:33:48.000000000 -0500
@@ -22,6 +22,24 @@
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
 	case "$uname" in
 		SunOS*)
@@ -67,6 +85,15 @@
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
@@ -90,8 +117,13 @@
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
@@ -119,10 +151,11 @@
 	DSOLIBS="\$(LIBZ)"
 	IMGLIBS=""
 
-	# Tell the run-time linkers where to find a DSO.  Some platforms
-	# need this option, even when the library is installed in a
-	# standard location...
-	case $uname in
+	if test x$enable_libtool = xno; then
+		# Tell the run-time linkers where to find a DSO.  Some platforms
+		# need this option, even when the library is installed in a
+		# standard location...
+		case $uname in
                 SunOS*)
                 	# Solaris...
 			if test $exec_prefix != /usr; then
@@ -147,7 +180,8 @@
 				EXPORT_LDFLAGS="-Wl,-rpath,$libdir"
 			fi
 			;;
-	esac
+		esac
+	fi
 else
 	DSOLIBS=""
 	IMGLIBS="\$(LIBZ)"
