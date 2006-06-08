# $NetBSD: Makefile,v 1.11 2006/06/08 19:55:16 joerg Exp $

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
