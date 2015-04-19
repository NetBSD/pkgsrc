$NetBSD: patch-gnats_ds-file_mkdb.sh,v 1.1 2015/04/19 19:35:00 spz Exp $

pkgsrcification

--- gnats/ds-file/mkdb.sh.orig	2015-01-17 16:41:05.000000000 +0000
+++ gnats/ds-file/mkdb.sh
@@ -27,7 +27,7 @@ export PATH
 
 GNATS_USER=@GNATS_USER@
 DATABASES=@GLOBAL_DB_LIST_FILE@
-DEFAULTSDIR="@sysconfdir@/gnats/defaults"
+DEFAULTSDIR="%%GNATS_DEFAULTS%%"
 
 domkdir() {
     mkdir -p "$1" || { echo "Can't create directory $1, exiting"; exit 1 ; }
