# $NetBSD: Makefile,v 1.12 2004/12/03 15:14:59 wiz Exp $

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
PKGREVISION=	2
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
