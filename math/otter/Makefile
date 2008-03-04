# $NetBSD: Makefile,v 1.15 2008/03/04 18:12:59 jlam Exp $

DISTNAME=	otter-3.0.6
CATEGORIES=	math
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/Otter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www-unix.mcs.anl.gov/AR/otter/
COMMENT=	Automated Deduction System

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	otter
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/source

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/otter ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/otter
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
