$NetBSD: patch-gnats_ds-file_mkdb.sh,v 1.2 2026/01/03 13:25:25 spz Exp $

pkgsrcification

we say to run this as GNATS_USER, the chowns don't do anything useful

we copy the gnatsd config files to SYSCONFIGDIR, not to defaults,
don't try to copy them from defaults to gnats-adm

--- gnats/ds-file/mkdb.sh.orig	2015-01-17 16:41:05.000000000 +0000
+++ gnats/ds-file/mkdb.sh
@@ -27,16 +27,20 @@ export PATH
 
 GNATS_USER=@GNATS_USER@
 DATABASES=@GLOBAL_DB_LIST_FILE@
-DEFAULTSDIR="@sysconfdir@/gnats/defaults"
+DEFAULTSDIR="%%GNATS_DEFAULTS%%"
 
 domkdir() {
     mkdir -p "$1" || { echo "Can't create directory $1, exiting"; exit 1 ; }
-    chown "${GNATS_USER}" "$1"
+    if [ `whoami` = "root" ]; then
+        chown "${GNATS_USER}" "$1"
+    fi
 }
 
 docp() {
     cp $DEFAULTSDIR/"$1" "$2" || { echo "Can't copy file $DEFAULTSDIR/$1 to $2, exiting"; exit 1 ; }
-    chown "${GNATS_USER}" "$2"
+    if [ `whoami` = "root" ]; then
+        chown "${GNATS_USER}" "$2"
+    fi
 }
 
 prog=mkdb
@@ -45,10 +49,10 @@ while [ $# -gt 0 ]; do
   case "$1" in
     -*)  echo "$USAGE" ; exit 1 ;;
      *)  if [ -n "$database" ] ; then
-	    echo "$USAGE" 1>&2 ; exit 1 ;
-	 else
-	    database="$1" ;
-	 fi ;;
+             echo "$USAGE" 1>&2 ; exit 1 ;
+         else
+             database="$1" ;
+         fi ;;
   esac
   shift
 done
@@ -85,8 +89,9 @@ echo "Copying default files from ${DEFAU
 docp categories "${dbdir}/gnats-adm/categories"
 docp submitters "${dbdir}/gnats-adm/submitters"
 docp responsible "${dbdir}/gnats-adm/responsible"
-docp gnatsd.user_access "${dbdir}/gnats-adm/gnatsd.user_access"
-chmod 600 "${dbdir}/gnats-adm/gnatsd.user_access"
+# pkgsrc has the *_access files in SYSCONFIGDIR
+#docp gnatsd.user_access "${dbdir}/gnats-adm/gnatsd.user_access"
+#chmod 600 "${dbdir}/gnats-adm/gnatsd.user_access"
 docp addresses "${dbdir}/gnats-adm/addresses"
 docp states "${dbdir}/gnats-adm/states"
 docp classes "${dbdir}/gnats-adm/classes"
