# $NetBSD: Makefile,v 1.3 2006/10/04 21:49:19 wiz Exp $
#

DISTNAME=		firelib-1.0.1
CATEGORIES=		misc
MASTER_SITES=		http://fire.org/downloads/fireLib/1.0.1/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://fire.org/
COMMENT=		Library for predicting fire spread rate, intensity, and more

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

MAKE_FILE=		makefile
BUILD_TARGET=		fireSim

INSTALLATION_DIRS=	bin include lib

post-build:
	cd  ${WRKSRC} && ${AR} cru libfire.a fireLib.o
	cd  ${WRKSRC} && ${RANLIB} libfire.a

do-install:
	${INSTALL_LIB} ${WRKSRC}/libfire.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/fireLib.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/fireSim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/firelib
	${INSTALL_DATA} ${WRKSRC}/firelib.ps ${PREFIX}/share/doc/firelib
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/firelib

.include "../../mk/bsd.pkg.mk"
