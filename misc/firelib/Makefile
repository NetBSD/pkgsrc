# $NetBSD: Makefile,v 1.6 2014/10/09 14:06:42 wiz Exp $
#

DISTNAME=		firelib-1.0.1
CATEGORIES=		misc
MASTER_SITES=		http://fire.org/downloads/fireLib/1.0.1/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://fire.org/
COMMENT=		Library for predicting fire spread rate, intensity, and more

WRKSRC=			${WRKDIR}

MAKE_FILE=		makefile
BUILD_TARGET=		fireSim

INSTALLATION_DIRS=	bin include lib

post-build:
	cd  ${WRKSRC} && ${AR} cru libfire.a fireLib.o
	cd  ${WRKSRC} && ${RANLIB} libfire.a

do-install:
	${INSTALL_LIB} ${WRKSRC}/libfire.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/fireLib.h ${DESTDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/fireSim ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/firelib
	${INSTALL_DATA} ${WRKSRC}/firelib.ps ${DESTDIR}${PREFIX}/share/doc/firelib
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/firelib

.include "../../mk/bsd.pkg.mk"
