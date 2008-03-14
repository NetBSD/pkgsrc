# $NetBSD: Makefile,v 1.22 2008/03/14 17:22:49 jlam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/freetype-lib/Makefile.common"

PKGNAME=	freetype-utils-${FT_VERS}
COMMENT=	Utilities for manipulating TrueType fonts

BUILDLINK_API_DEPENDS.freetype=	freetype-lib>=${FT_VERS}

CONFIGURE_ARGS+=	--with-x
BUILD_TARGET=		tttest
INSTALL_TARGET=		install-tttest

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
