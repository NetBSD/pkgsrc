# $NetBSD: Makefile,v 1.11 2004/10/03 00:14:50 tv Exp $

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
PKGREVISION=	2
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
