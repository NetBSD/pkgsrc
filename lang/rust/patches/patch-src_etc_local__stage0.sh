$NetBSD: patch-src_etc_local__stage0.sh,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Copy additional libarena required on Darwin.
Copy GCC support libraries required on SunOS.

--- src/etc/local_stage0.sh.orig	2016-08-16 01:54:35.000000000 +0000
+++ src/etc/local_stage0.sh
@@ -51,6 +51,7 @@ fi
 
 cp ${PREFIX}/bin/rustc${BIN_SUF} ${TARG_DIR}/stage0/bin/
 cp ${PREFIX}/${LIB_DIR}/${RUSTLIBDIR}/${TARG_DIR}/${LIB_DIR}/* ${TARG_DIR}/stage0/${LIB_DIR}/
+cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}arena*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}extra*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}rust*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}std*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
@@ -63,6 +64,9 @@ cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}log
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}rbml*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}serialize*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
 cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}term*${LIB_SUF} ${TARG_DIR}/stage0/${LIB_DIR}/
+cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}gcc_s*${LIB_SUF}* ${TARG_DIR}/stage0/${LIB_DIR}/
+cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}ssp*${LIB_SUF}* ${TARG_DIR}/stage0/${LIB_DIR}/
+cp ${PREFIX}/${LIB_DIR}/${LIB_PREFIX}stdc++*${LIB_SUF}* ${TARG_DIR}/stage0/${LIB_DIR}/
 
 # do not fail if one of the above fails, as all we need is a working rustc!
 exit 0
