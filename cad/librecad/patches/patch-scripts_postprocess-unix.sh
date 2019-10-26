$NetBSD: patch-scripts_postprocess-unix.sh,v 1.4 2019/10/26 12:23:01 kamil Exp $

Fix QTDIR.

--- scripts/postprocess-unix.sh.orig	2018-02-15 20:54:45.000000000 +0000
+++ scripts/postprocess-unix.sh
@@ -8,7 +8,7 @@ APPDATADIR="${THISDIR}/unix/appdata"
 TSDIRLC="${LCDIR}/ts"
 TSDIRPI="${PIDIR}/ts"
 SPTDIR="${LCDIR}/support"
-LRELEASE="lrelease"
+LRELEASE="@QTDIR@/bin/lrelease"
 
 cd "${THISDIR}"
 
