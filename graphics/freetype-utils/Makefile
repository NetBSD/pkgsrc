# $NetBSD: Makefile,v 1.9 2001/10/23 13:14:57 jlam Exp $

PKGNAME=		freetype-utils-${FT_VERS}
COMMENT=		Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}
USE_BUILDLINK_ONLY=	# defined

.include "../freetype-lib/Makefile.common"

CONFIGURE_ARGS+=	--with-x
ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
