# $NetBSD: Makefile,v 1.12 2007/02/15 14:42:17 joerg Exp $

.include "../../print/ja-vflib-lib/Makefile.common"

PKGNAME=	ja-vflib-utils-${VFLIB_VERSION}
PKGREVISION=	2
COMMENT=	Utilities for manipulating VFlib vector font files

BUILDLINK_API_DEPENDS.vflib+=	ja-vflib-lib>=${VFLIB_VERSION}

CONFIGURE_ARGS+=	--enable-tools --with-x

USE_TOOLS+=	xmkmf

BUILD_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
