# $NetBSD: Makefile,v 1.17 2012/09/02 12:10:20 marino Exp $

PKGNAME=	gnuradio-core-docs-${VERSION}
COMMENT=	GNU Radio core module documentation
PKGREVISION=	13

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONFIGURE_ARGS+=--enable-doxygen

BUILD_DEPENDS+=doxygen>=1.8.2:../../devel/doxygen

BUILD_DIRS=	docs

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
