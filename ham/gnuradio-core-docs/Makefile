# $NetBSD: Makefile,v 1.11 2012/01/09 02:54:27 obache Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	7

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.6.3:../../devel/doxygen

BUILD_DIRS=	docs

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
