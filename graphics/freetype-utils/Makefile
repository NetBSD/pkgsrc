# $NetBSD: Makefile,v 1.8 2001/09/09 04:12:49 jlam Exp $

PKGNAME=		freetype-utils-${FT_VERS}
COMMENT=		Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}
USE_BUILDLINK_ONLY=	# defined

.include "../freetype-lib/Makefile.common"

CONFIGURE_ARGS+=	--with-x
ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
