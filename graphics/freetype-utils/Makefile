# $NetBSD: Makefile,v 1.10.2.1 2002/06/06 06:54:39 jlam Exp $

PKGNAME=		freetype-utils-${FT_VERS}
COMMENT=		Utilities for manipulating TrueType fonts

BUILDLINK_DEPENDS.freetype=	freetype-lib>=${FT_VERS}
USE_BUILDLINK2_ONLY=	# defined
USE_X11=		# defined

.include "../freetype-lib/Makefile.common"

CONFIGURE_ARGS+=	--with-x
ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
