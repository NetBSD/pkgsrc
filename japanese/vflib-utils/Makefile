# $NetBSD: Makefile,v 1.6.2.1 2002/06/06 06:54:43 jlam Exp $

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}
COMMENT=		Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib=ja-vflib-lib>=${VFLIB_VERSION}
USE_BUILDLINK2_ONLY=	# defined

.include "../vflib-lib/Makefile.common"

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../japanese/vflib-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
