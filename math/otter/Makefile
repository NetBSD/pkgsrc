# $NetBSD: Makefile,v 1.19 2026/07/26 18:24:38 rillig Exp $

DISTNAME=	otter-3.0.6
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://www.cs.unm.edu/~mccune/otter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.unm.edu/~mccune/otter/
COMMENT=	Automated Deduction System
LICENSE=	public-domain

BUILD_DIRS=	source
BUILD_TARGET=	otter

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/otter ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Announce Changelog		\
		Copying README* ${DESTDIR}${PREFIX}/share/doc/otter
	for d in auto fringe ivy kalman misc program split wos;	do	\
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/otter/$$d;\
	${INSTALL_DATA} ${WRKSRC}/examples/$$d/*			\
		${DESTDIR}${PREFIX}/share/examples/otter/$$d;		\
	done
	cd ${WRKSRC}/examples && ${INSTALL_DATA} Run_all \
		objects	summary ${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKSRC}/examples/README 			\
		${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKSRC}/document/* 				\
		${DESTDIR}${PREFIX}/share/doc/otter

.include "../../mk/bsd.pkg.mk"
