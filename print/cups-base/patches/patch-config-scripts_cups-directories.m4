$NetBSD: patch-config-scripts_cups-directories.m4,v 1.4 2022/05/10 20:47:37 markd Exp $

The '$' while loops expand the variables as long as possible so that no
references to other variables occur. This is necessary because fontpath
may be "${exec_prefix}", which itself may be "${prefix}", and so on. I
don't know how many levels of indirection are possible, therefore the
loop.

I'm also sure that this is not the Right Way to fix it, but at least it
works.

--- config-scripts/cups-directories.m4.orig	2022-01-27 11:11:42.000000000 +0000
+++ config-scripts/cups-directories.m4
@@ -95,7 +95,7 @@ AS_IF([test "$sysconfdir" = "\${prefix}/
 dnl Fix "libdir" variable...
 AS_IF([test "$libdir" = "\${exec_prefix}/lib"], [
     AS_CASE(["$host_os_name"], [linux*], [
-	AS_IF([test -d /usr/lib64 -a ! -d /usr/lib64/fakeroot], [
+	AS_IF([test -d /usr/lib64 -a ! -d /usr/lib64/fakeroot && false], [
 	    libdir="$exec_prefix/lib64"
 	], [
 	    libdir="$exec_prefix/lib"
@@ -132,7 +132,15 @@ AC_SUBST([CUPS_CACHEDIR])
 
 # Data files
 CUPS_DATADIR="$datadir/cups"
-AC_DEFINE_UNQUOTED([CUPS_DATADIR], ["$datadir/cups"], [Location of data files.])
+done=no
+while test $done = no; do
+	case "$CUPS_DATADIR" in
+	*'$'*) eval "CUPS_DATADIR=$CUPS_DATADIR";;
+	*) done=yes;;
+	esac
+done
+
+AC_DEFINE_UNQUOTED([CUPS_DATADIR], ["$CUPS_DATADIR"], [Location of data files.])
 AC_SUBST([CUPS_DATADIR])
 
 # Icon directory
@@ -145,7 +153,11 @@ AC_ARG_WITH([icondir], AS_HELP_STRING([-
 AS_IF([test "x$icondir" = x], [
     ICONDIR="/usr/share/icons"
 ], [
-    ICONDIR="$icondir"
+    if test "x$icondir" = xno; then
+            ICONDIR=""
+    else
+            ICONDIR="$icondir"
+    fi
 ])
 
 AC_SUBST([ICONDIR])
@@ -160,6 +172,11 @@ AC_ARG_WITH([menudir], AS_HELP_STRING([-
 AS_IF([test "x$menudir" = x], [
     MENUDIR="/usr/share/applications"
 ], [
+    if test "x$menudir" = xno; then
+           MENUDIR=""
+    else
+           MENUDIR="$menudir"
+    fi
     MENUDIR="$menudir"
 ])
 
@@ -179,7 +196,15 @@ AS_IF([test x$docdir = x], [
     CUPS_DOCROOT="$docdir"
 ])
 
-AC_DEFINE_UNQUOTED([CUPS_DOCROOT], ["$docdir"], [Location of documentation files.])
+done=no
+while test $done = no; do
+	case "$CUPS_DOCROOT" in
+	*'$'*) eval "CUPS_DOCROOT=$CUPS_DOCROOT";;
+	*) done=yes;;
+	esac
+done
+
+AC_DEFINE_UNQUOTED([CUPS_DOCROOT], ["$CUPS_DOCROOT"], [Location of documentation files.])
 AC_SUBST([CUPS_DOCROOT])
 
 # Locale data
@@ -194,6 +219,14 @@ AS_IF([test "$localedir" = "\${datarootd
     CUPS_LOCALEDIR="$localedir"
 ])
 
+done=no
+while test $done = no; do
+	case "$CUPS_LOCALEDIR" in
+	*'$'*) eval "CUPS_LOCALEDIR=$CUPS_LOCALEDIR";;
+	*) done=yes;;
+	esac
+done
+
 AC_DEFINE_UNQUOTED([CUPS_LOCALEDIR], ["$CUPS_LOCALEDIR"], [Location of localization files.])
 AC_SUBST([CUPS_LOCALEDIR])
 
@@ -232,10 +265,18 @@ AC_SUBST([CUPS_LOGDIR])
 
 # Longer-term spool data
 CUPS_REQUESTS="$localstatedir/spool/cups"
-AC_DEFINE_UNQUOTED([CUPS_REQUESTS], ["$localstatedir/spool/cups"], [Location of spool directory.])
+AC_DEFINE_UNQUOTED([CUPS_REQUESTS], ["$CUPS_REQUESTS"], [Location of spool directory.])
 AC_SUBST([CUPS_REQUESTS])
 
 # Server executables...
+AC_ARG_WITH([serverbindir], AS_HELP_STRING([--with-serverbindir], [set path for server helper programs]), [
+    serverbindir="$withval"
+], [
+    serverbindir=""
+])
+
+if test x$serverbindir = x; then
+
 AS_CASE(["$host_os_name"], [*-gnu], [
     # GNUs
     INSTALL_SYSV="install-sysv"
@@ -250,13 +291,18 @@ AS_CASE(["$host_os_name"], [*-gnu], [
     CUPS_SERVERBIN="$exec_prefix/lib/cups"
 ])
 
+else
+	INSTALL_SYSV=""
+	CUPS_SERVERBIN="$serverbindir"
+fi
+
 AC_DEFINE_UNQUOTED([CUPS_SERVERBIN], ["$CUPS_SERVERBIN"], [Location of server programs.])
 AC_SUBST([CUPS_SERVERBIN])
 AC_SUBST([INSTALL_SYSV])
 
 # Configuration files
 CUPS_SERVERROOT="$sysconfdir/cups"
-AC_DEFINE_UNQUOTED([CUPS_SERVERROOT], ["$sysconfdir/cups"], [Location of server configuration files.])
+AC_DEFINE_UNQUOTED([CUPS_SERVERROOT], ["$CUPS_SERVERROOT"], [Location of server configuration files.])
 AC_SUBST([CUPS_SERVERROOT])
 
 # Transient run-time state
