# $NetBSD: Makefile,v 1.19 2006/04/06 06:22:02 reed Exp $

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
PKGREVISION=	2
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_API_DEPENDS.freetype=	freetype-lib>=${FT_VERS}


CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
