# $NetBSD: Makefile,v 1.17 2005/12/05 20:50:19 rillig Exp $

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
PKGREVISION=	1
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}


CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
