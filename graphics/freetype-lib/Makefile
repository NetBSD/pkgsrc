# $NetBSD: Makefile,v 1.15 2008/03/14 17:22:49 jlam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
