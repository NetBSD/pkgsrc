# $NetBSD: Makefile,v 1.12 2002/09/11 08:52:58 jlam Exp $

.include "../freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}
USE_X11=		# defined

CONFIGURE_ARGS+=	--with-x
ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
