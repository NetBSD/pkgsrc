$NetBSD: patch-be,v 1.1 2014/06/20 05:24:32 jnemeth Exp $

--- rmail/Makefile.m4.orig	2014-03-06 17:31:31.000000000 +0000
+++ rmail/Makefile.m4
@@ -31,7 +31,7 @@ defeat-install:
 force-install: install-rmail ifdef(`confNO_MAN_BUILD',, `install-docs')
 
 install-rmail: rmail
-	${INSTALL} -c -o ${UBINOWN} -g ${UBINGRP} -m ${UBINMODE} rmail ${DESTDIR}${UBINDIR}
+	${INSTALL} -c -m ${UBINMODE} rmail ${DESTDIR}${UBINDIR}
 divert
 
 bldFINISH
