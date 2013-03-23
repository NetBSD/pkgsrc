# $NetBSD: Makefile,v 1.20 2013/03/23 10:04:35 joerg Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	15

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.8.3.1:../../devel/doxygen

BUILD_DIRS=	docs

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
