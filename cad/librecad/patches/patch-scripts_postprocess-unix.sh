$NetBSD: patch-scripts_postprocess-unix.sh,v 1.5 2025/01/20 23:29:25 gdt Exp $

Fix QTDIR.

--- scripts/postprocess-unix.sh.orig	2022-12-17 11:13:13.000000000 +0000
+++ scripts/postprocess-unix.sh
@@ -9,7 +9,7 @@ TSDIRLC="${LCDIR}/ts"
 TSDIRPI="${PIDIR}/ts"
 SPTDIR="${LCDIR}/support"
 DESKTOPDIR="${THISDIR}/desktop"
-LRELEASE="lrelease"
+LRELEASE="@QTDIR@/bin/lrelease"
 
 cd "${THISDIR}"
 
