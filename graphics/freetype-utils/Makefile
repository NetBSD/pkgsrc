# $NetBSD: Makefile,v 1.3 2001/05/28 03:16:44 jlam Exp $

PKGNAME=		freetype-utils-${FT_VERS}

COMMENT=		Utilities for manipulating TrueType fonts

FREETYPE_REQD=		${FT_VERS}

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-x

ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../graphics/freetype-lib/Makefile.common"
