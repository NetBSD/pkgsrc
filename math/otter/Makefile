# $NetBSD: Makefile,v 1.5 2001/04/25 23:35:30 jtb Exp $

DISTNAME=	otter-3.0.6
CATEGORIES=	math
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/Otter/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mcs.anl.gov/AR/otter/
COMMENT=	Automated Deduction System

WRKSRC=		${WRKDIR}/${PKGNAME}/source

ALL_TARGET=	otter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otter ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/otter
	cd ${WRKDIR}/${PKGNAME} && ${INSTALL_DATA} Announce Changelog 	\
		Copying README* ${PREFIX}/share/doc/otter
	for d in auto fringe ivy kalman misc program split wos;	do	\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter/$$d;		\
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/examples/$$d/*		\
		${PREFIX}/share/examples/otter/$$d;			\
	done
	cd ${WRKDIR}/${PKGNAME}/examples && ${INSTALL_SCRIPT} Run_all 	\
		objects	summary ${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/examples/README 		\
		${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/document/* 		\
		${PREFIX}/share/doc/otter

.include "../../mk/bsd.pkg.mk"
