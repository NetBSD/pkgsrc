# $NetBSD: Makefile,v 1.9 2010/07/01 15:59:26 joerg Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	5

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.6.3:../../devel/doxygen

BUILD_DIRS=	docs

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
