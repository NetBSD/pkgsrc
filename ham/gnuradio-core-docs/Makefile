# $NetBSD: Makefile,v 1.18 2012/10/03 13:01:44 asau Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	13

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.8.2:../../devel/doxygen

BUILD_DIRS=	docs

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
