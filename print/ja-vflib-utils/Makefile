# $NetBSD: Makefile,v 1.4 2004/04/26 01:30:42 snj Exp $

.include "../../print/ja-vflib-lib/Makefile.common"

PKGNAME=	ja-vflib-utils-${VFLIB_VERSION}
COMMENT=	Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib=ja-vflib-lib>=${VFLIB_VERSION}

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../print/ja-vflib-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
