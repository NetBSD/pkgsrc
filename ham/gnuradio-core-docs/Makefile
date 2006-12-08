# $NetBSD: Makefile,v 1.2 2006/12/08 11:02:44 joerg Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS=	make pkg-config
CONFIGURE_ARGS+=--enable-doxygen

do-build:
	cd ${WRKSRC}/gnuradio-core/doc && make

do-install:
	cd ${WRKSRC}/gnuradio-core/doc && make install

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
