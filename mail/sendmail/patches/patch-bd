$NetBSD: patch-bd,v 1.1 2014/06/20 05:24:32 jnemeth Exp $

--- mail.local/Makefile.m4.orig	2014-03-06 17:31:30.000000000 +0000
+++ mail.local/Makefile.m4
@@ -30,7 +30,7 @@ install:
 force-install: install-mail.local ifdef(`confNO_MAN_BUILD',, `install-docs')
 
 install-mail.local: mail.local
-	${INSTALL} -c -o ${UBINOWN} -g ${UBINGRP} -m ${UBINMODE} mail.local ${DESTDIR}${EBINDIR}
+	${INSTALL} -c -m ${UBINMODE} mail.local ${DESTDIR}${EBINDIR}
 divert
 
 bldFINISH
