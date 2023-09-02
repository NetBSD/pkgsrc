$NetBSD: patch-Makefile.gnu,v 1.1 2023/09/02 21:32:11 vins Exp $

Fix install target for pkgsrc.

--- Makefile.gnu.orig	2021-06-02 10:48:50.000000000 +0000
+++ Makefile.gnu
@@ -27,8 +27,7 @@ SYMBOL_LIST=	${CURDIR}/Symbols.list
 includes:
 	@cd ${CURDIR}; for i in ${HDRS}; do \
 	    j="cmp -s $$i ${DESTDIR}${LOCALBASE}/include/$$i || \
-	    ${INSTALL} -D -o ${BINOWN} -g ${BINGRP} -m 444 $$i\
-		${DESTDIR}${LOCALBASE}/include/$$i"; \
+	    ${BSD_INSTALL_DATA} $$i ${DESTDIR}${LOCALBASE}/include"; \
 	    echo $$j; \
 	    eval "$$j"; \
 	done;
@@ -41,11 +40,11 @@ ${VERSION_SCRIPT}: ${SYMBOL_LIST}
 # Defines for OpenBSD-specific interfaces
 # Add a OS-specific defines here.
 NEED_EXPLICIT_BZERO?=	0
-NEED_RECALLOCARRAY?=	1
+NEED_RECALLOCARRAY?=	0
 NEED_REALLOCARRAY?=	0
-NEED_STRLCAT?=		1
-NEED_STRLCPY?=		1
-NEED_STRTONUM?=		1
+NEED_STRLCAT?=		0
+NEED_STRLCPY?=		0
+NEED_STRTONUM?=		0
 
 MANFORMAT?=		mangz
 
@@ -138,10 +137,10 @@ all: ${TARGET_LIB} ${TARGET_MAN}
 
 .PHONY: install
 install: includes ${TARGET_LIB} ${TARGET_MAN}
-	${INSTALL} -D -o ${BINOWN} -g ${BINGRP} -m ${LIBPERM} ${TARGET_LIB} ${DESTDIR}${LIBDIR}/${TARGET_LIB}
-	${LINK} -s ${TARGET_LIB} ${DESTDIR}${LIBDIR}/${SONAME_LIB}
-	${LINK} -s ${TARGET_LIB} ${DESTDIR}${LIBDIR}/${BASE_LIB}
-	${INSTALL} -D -o ${MANOWN} -g ${MANGRP} -m ${MANPERM} ${TARGET_MAN} ${DESTDIR}${MANDIR}/${TARGET_MAN}
+	${BSD_INSTALL_LIB} ${TARGET_LIB} ${DESTDIR}${LIBDIR}
+	${LINK} ${TARGET_LIB} ${DESTDIR}${LIBDIR}/${SONAME_LIB}
+	${LINK} ${TARGET_LIB} ${DESTDIR}${LIBDIR}/${BASE_LIB}
+	${BSD_INSTALL_MAN} ${TARGET_MAN} ${DESTDIR}${MANDIR}
 
 CLEANFILES+=	*.o ${TARGET_LIB}
 
