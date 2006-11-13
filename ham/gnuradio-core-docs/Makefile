# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 17:08:51 wulf Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS=	make
CONFIGURE_ARGS+=--enable-doxygen

do-build:
	cd ${WRKSRC}/gnuradio-core/doc && make

do-install:
	cd ${WRKSRC}/gnuradio-core/doc && make install

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
