# $NetBSD: Makefile,v 1.1 2023/05/20 13:26:51 thorpej Exp $

# The author has not yet created any tags, so we will dates as tiny revs
# off 0.0.x for now.
ISHKUR_VERSION=	0.0.20230518

DISTNAME=	IshkurCPM-${ISHKUR_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=tergav17/}
GITHUB_TAG=	b8f8bea67147fb2bea6e435efb6b4ec71afa6def

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/tergav17/IshkurCPM
COMMENT=	Open source, modular CP/M distribution for the NABU computer
LICENSE=	gnu-gpl-v3

ISHKUR_LOC=	share/IshkurCPM
ISHKUR_BOOT=	${ISHKUR_LOC}/boot
ISHKUR_BIN=	${ISHKUR_LOC}/bin
ISHKUR_SYS=	${ISHKUR_LOC}/sys

INSTALLATION_DIRS= ${ISHKUR_LOC} ${ISHKUR_BOOT} ${ISHKUR_BIN} ${ISHKUR_SYS}

do-build:

do-install:
	for file in ${WRKSRC}/Output/*.nabu; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/${ISHKUR_BOOT}; \
	done
	for file in ${WRKSRC}/Output/*.SYS; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/${ISHKUR_SYS}; \
	done
	for file in ${WRKSRC}/Output/*.GRB; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/${ISHKUR_BIN}; \
	done
	for file in ${WRKSRC}/Directory/*.COM; do \
		${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/${ISHKUR_BIN}; \
	done
	for file in ${WRKSRC}/Directory/*.com; do \
		dfname=`basename $$file | tr "[:lower:]" "[:upper:]"`; \
		${INSTALL_DATA} $$file \
		    ${DESTDIR}${PREFIX}/${ISHKUR_BIN}/$$dfname; \
	done

.include "../../mk/bsd.pkg.mk"
