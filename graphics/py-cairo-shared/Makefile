# $NetBSD: Makefile,v 1.2 2024/02/19 12:40:56 wiz Exp $

PKGNAME=	py-cairo-shared-${PYCAIRO_VER}

COMMENT=	Non version specific parts of py-cairo

.include "../../graphics/py-cairo/Makefile.common"

INSTALLATION_DIRS=	include/pycairo lib/pkgconfig

do-build:
	${SED} -e "s/@PYCAIRO_VER@/${PYCAIRO_VER}/" -e "s:@PREFIX@:${PREFIX}:" \
		 ${FILESDIR}/py3cairo.pc > ${WRKSRC}/py3cairo.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/cairo/py3cairo.h ${DESTDIR}${PREFIX}/include/pycairo
	${INSTALL_DATA} ${WRKSRC}/py3cairo.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
