# $NetBSD: Makefile,v 1.15 2004/12/03 15:14:59 wiz Exp $

.include "../freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
PKGREVISION=	1
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}

USE_X11=		# defined

CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
