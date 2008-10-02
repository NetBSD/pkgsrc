# $NetBSD: Makefile,v 1.5 2008/10/02 19:08:32 joerg Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	1

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS=	make pkg-config
CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.5.6:../../devel/doxygen

do-build:
	cd ${WRKSRC}/gnuradio-core/doc && make

do-install:
	cd ${WRKSRC}/gnuradio-core/doc && make install

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
