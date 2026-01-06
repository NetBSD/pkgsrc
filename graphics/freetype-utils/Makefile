# $NetBSD: Makefile,v 1.27 2026/01/06 22:28:02 wiz Exp $

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
PKGREVISION=	4
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_API_DEPENDS.freetype=	freetype-lib>=${FT_VERS}

CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
