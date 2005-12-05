# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:53 rillig Exp $

.include "../../print/ja-vflib-lib/Makefile.common"

PKGNAME=	ja-vflib-utils-${VFLIB_VERSION}
PKGREVISION=	1
COMMENT=	Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib+=	ja-vflib-lib>=${VFLIB_VERSION}

CONFIGURE_ARGS+=	--enable-tools --with-x

BUILD_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
