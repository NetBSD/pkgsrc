$NetBSD: patch-bf,v 1.1 2014/06/20 16:26:55 jnemeth Exp $

--- libmilter/Makefile.m4.orig	2014-05-16 20:40:15.000000000 +0000
+++ libmilter/Makefile.m4
@@ -33,8 +33,8 @@ MFAPI=	${SRCDIR}/inc`'lude/libmilter/mfa
 MFDEF=	${SRCDIR}/inc`'lude/libmilter/mfdef.h
 install-mfapi: ${MFAPI}
 	if [ ! -d ${DESTDIR}${INCLUDEDIR}/libmilter ]; then mkdir -p ${DESTDIR}${INCLUDEDIR}/libmilter; else :; fi
-	${INSTALL} -c -o ${INCOWN} -g ${INCGRP} -m ${INCMODE} ${MFAPI} ${DESTDIR}${INCLUDEDIR}/libmilter/mfapi.h
-	${INSTALL} -c -o ${INCOWN} -g ${INCGRP} -m ${INCMODE} ${MFDEF} ${DESTDIR}${INCLUDEDIR}/libmilter/mfdef.h
+	${INSTALL} -c -m ${INCMODE} ${MFAPI} ${DESTDIR}${INCLUDEDIR}/libmilter/mfapi.h
+	${INSTALL} -c -m ${INCMODE} ${MFDEF} ${DESTDIR}${INCLUDEDIR}/libmilter/mfdef.h
 divert(0)
 
 bldFINISH
