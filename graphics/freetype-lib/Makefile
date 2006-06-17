# $NetBSD: Makefile,v 1.14 2006/06/17 19:41:32 minskim Exp $

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
