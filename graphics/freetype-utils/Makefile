# $NetBSD: Makefile,v 1.20 2006/06/17 19:41:33 minskim Exp $

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_API_DEPENDS.freetype=	freetype-lib>=${FT_VERS}


CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
