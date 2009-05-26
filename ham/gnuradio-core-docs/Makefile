# $NetBSD: Makefile,v 1.7 2009/05/26 05:55:15 hasso Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	3

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS=	make pkg-config
CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.5.7.1:../../devel/doxygen

do-build:
	cd ${WRKSRC}/gnuradio-core/doc && make

do-install:
	cd ${WRKSRC}/gnuradio-core/doc && make install

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
