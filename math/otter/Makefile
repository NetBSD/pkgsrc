# $NetBSD: Makefile,v 1.18 2026/07/26 06:14:12 rillig Exp $

DISTNAME=	otter-3.0.6
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.cs.unm.edu/~mccune/otter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.unm.edu/~mccune/otter/
COMMENT=	Automated Deduction System

BUILD_DIRS=	source
BUILD_TARGET=	otter

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/otter ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/${PKGNAME_NOREV} && ${INSTALL_DATA} Announce Changelog \
		Copying README* ${DESTDIR}${PREFIX}/share/doc/otter
	for d in auto fringe ivy kalman misc program split wos;	do	\
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/otter/$$d;\
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/examples/$$d/*	\
		${DESTDIR}${PREFIX}/share/examples/otter/$$d;		\
	done
	cd ${WRKDIR}/${PKGNAME_NOREV}/examples && ${INSTALL_SCRIPT} Run_all \
		objects	summary ${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/examples/README 	\
		${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/document/* 		\
		${DESTDIR}${PREFIX}/share/doc/otter

.include "../../mk/bsd.pkg.mk"
