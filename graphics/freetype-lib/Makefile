# $NetBSD: Makefile,v 1.10 2003/07/13 13:52:00 wiz Exp $

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
PKGREVISION=	1
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
