# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:01:08 seb Exp $

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}
COMMENT=		Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib=ja-vflib-lib>=${VFLIB_VERSION}
USE_BUILDLINK_ONLY=	# defined

.include "../../print/ja-vflib-lib/Makefile.common"

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../print/ja-vflib-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
