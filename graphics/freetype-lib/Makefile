# $NetBSD: Makefile,v 1.9 2002/09/11 08:52:57 jlam Exp $

.include "Makefile.common"

PKGNAME=	freetype-lib-${FT_VERS}
COMMENT=	TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
