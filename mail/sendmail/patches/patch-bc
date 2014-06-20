$NetBSD: patch-bc,v 1.1 2014/06/20 05:24:32 jnemeth Exp $

--- devtools/M4/UNIX/manpage.m4.orig	2014-03-06 17:31:29.000000000 +0000
+++ devtools/M4/UNIX/manpage.m4
@@ -69,10 +69,10 @@ ifdef(`confNO_MAN_INSTALL', `divert(-1)'
 define(`bldMAN_INSTALL_CMD',
 `ifdef(`confDONT_INSTALL_CATMAN', `dnl',
 `	ifdef(`confMKDIR', `if [ ! -d ${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`SRC} ]; then confMKDIR -p ${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`SRC}; else :; fi ')
-	${INSTALL} -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} bldGET_MAN_BASE_NAME($1).`${MAN'bldGET_MAN_SOURCE_NUM($1)`SRC}' `${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)}/bldGET_MAN_BASE_NAME($1)`.${MAN'bldGET_MAN_SOURCE_NUM($1)`EXT}'')
+	${INSTALL} -c -m ${MANMODE} bldGET_MAN_BASE_NAME($1).`${MAN'bldGET_MAN_SOURCE_NUM($1)`SRC}' `${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)}/bldGET_MAN_BASE_NAME($1)`.${MAN'bldGET_MAN_SOURCE_NUM($1)`EXT}'')
 ifdef(`confINSTALL_RAWMAN',
 `	ifdef(`confMKDIR', `if [ ! -d ${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`MAN} ]; then confMKDIR -p ${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`MAN}; else :; fi ')
-	${INSTALL} -c -o ${MANOWN} -g ${MANGRP} -m ${MANMODE} bldGET_MAN_BASE_NAME($1).bldGET_MAN_SOURCE_NUM($1) `${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`MAN}'/bldGET_MAN_BASE_NAME($1)`.${MAN'bldGET_MAN_SOURCE_NUM($1)`EXT}'', `dnl')'
+	${INSTALL} -c -m ${MANMODE} bldGET_MAN_BASE_NAME($1).bldGET_MAN_SOURCE_NUM($1) `${DESTDIR}${MAN'bldGET_MAN_SOURCE_NUM($1)`MAN}'/bldGET_MAN_BASE_NAME($1)`.${MAN'bldGET_MAN_SOURCE_NUM($1)`EXT}'', `dnl')'
 )dnl
 bldFOREACH(`bldMAN_INSTALL_CMD(', `bldMAN_PAGES')
 ifdef(`confNO_MAN_INSTALL', `divert(0)', `dnl')
