$NetBSD: patch-ba,v 1.3 2014/06/20 05:24:32 jnemeth Exp $

--- devtools/M4/UNIX/executable.m4.orig	2014-03-06 17:31:29.000000000 +0000
+++ devtools/M4/UNIX/executable.m4
@@ -31,7 +31,7 @@ ifdef(`bldLINK_SOURCES', `bldMAKE_SOURCE
 ifdef(`bldNO_INSTALL', ,
 `install-`'bldCURRENT_PRODUCT: bldCURRENT_PRODUCT ifdef(`bldTARGET_INST_DEP', `bldTARGET_INST_DEP')
 	ifdef(`confMKDIR', `if [ ! -d ${DESTDIR}${bldINSTALL_DIR`'BINDIR} ]; then confMKDIR -p ${DESTDIR}${bldINSTALL_DIR`'BINDIR}; else :; fi ')
-	${INSTALL} -c -o ${bldBIN_TYPE`'BINOWN} -g ${bldBIN_TYPE`'BINGRP} -m ${bldBIN_TYPE`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${bldINSTALL_DIR`'BINDIR}
+	${INSTALL} -c -m ${bldBIN_TYPE`'BINMODE} bldCURRENT_PRODUCT ${DESTDIR}${bldINSTALL_DIR`'BINDIR}
 ifdef(`bldTARGET_LINKS', `bldMAKE_TARGET_LINKS(${bldINSTALL_DIR`'BINDIR}/bldCURRENT_PRODUCT, ${bldCURRENT_PRODUCT`'TARGET_LINKS})')')
 
 strip-`'bldCURRENT_PRODUCT: bldCURRENT_PRODUCT
