$NetBSD: patch-bb,v 1.1 2014/06/20 05:24:32 jnemeth Exp $

--- devtools/M4/UNIX/library.m4.orig	2014-03-06 17:31:29.000000000 +0000
+++ devtools/M4/UNIX/library.m4
@@ -28,7 +28,7 @@ ifdef(`bldLINK_SOURCES', `bldMAKE_SOURCE
 
 install-`'bldCURRENT_PRODUCT: bldCURRENT_PRODUCT.a
 ifdef(`bldINSTALLABLE', `	ifdef(`confMKDIR', `if [ ! -d ${DESTDIR}${bldINSTALL_DIR`'LIBDIR} ]; then confMKDIR -p ${DESTDIR}${bldINSTALL_DIR`'LIBDIR}; else :; fi ')
-	${INSTALL} -c -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} bldCURRENT_PRODUCT.a ${DESTDIR}${LIBDIR}')
+	${INSTALL} -c -m ${LIBMODE} bldCURRENT_PRODUCT.a ${DESTDIR}${LIBDIR}')
 
 bldCURRENT_PRODUCT-clean:
 	rm -f ${OBJS} bldCURRENT_PRODUCT.a ${MANPAGES}
