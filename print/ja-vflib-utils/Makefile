# $NetBSD: Makefile,v 1.6 2004/12/03 15:15:07 wiz Exp $

.include "../../print/ja-vflib-lib/Makefile.common"

PKGNAME=	ja-vflib-utils-${VFLIB_VERSION}
PKGREVISION=	1
COMMENT=	Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib=ja-vflib-lib>=${VFLIB_VERSION}

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

BUILD_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
