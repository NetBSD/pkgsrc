# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:20 jlam Exp $

DISTNAME=	otter-3.0.6
CATEGORIES=	math
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/Otter/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mcs.anl.gov/AR/otter/
COMMENT=	Automated Deduction System

BUILD_TARGET=	otter
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/source

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otter ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/otter
	cd ${WRKDIR}/${PKGNAME_NOREV} && ${INSTALL_DATA} Announce Changelog \
		Copying README* ${PREFIX}/share/doc/otter
	for d in auto fringe ivy kalman misc program split wos;	do	\
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/otter/$$d;		\
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/examples/$$d/*	\
		${PREFIX}/share/examples/otter/$$d;			\
	done
	cd ${WRKDIR}/${PKGNAME_NOREV}/examples && ${INSTALL_SCRIPT} Run_all \
		objects	summary ${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/examples/README 	\
		${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/document/* 		\
		${PREFIX}/share/doc/otter

.include "../../mk/bsd.pkg.mk"
