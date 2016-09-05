$NetBSD: patch-scripts_postprocess-unix.sh,v 1.3 2016/09/05 21:13:21 plunky Exp $

* Set Qt tools path

--- scripts/postprocess-unix.sh.orig	2016-06-20 18:43:27.000000000 +0000
+++ scripts/postprocess-unix.sh
@@ -8,7 +8,7 @@ APPDATADIR="${THISDIR}/unix/appdata"
 TSDIRLC="${LCDIR}/ts"
 TSDIRPI="${PIDIR}/ts"
 SPTDIR="${LCDIR}/support"
-LRELEASE="lrelease"
+LRELEASE="@QTDIR@/bin/lrelease"

 cd "${THISDIR}"
