# $NetBSD: Makefile,v 1.16 2011/04/22 13:42:06 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
PKGREVISION=	1
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
