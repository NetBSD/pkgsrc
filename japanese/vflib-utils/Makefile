# $NetBSD: Makefile,v 1.5 2001/09/09 03:37:01 jlam Exp $

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}
COMMENT=		Utilities for manipulating VFlib vector font files

BUILDLINK_DEPENDS.vflib=	ja-vflib-lib>=${VFLIB_VERSION}

USE_BUILDLINK_ONLY=	# defined
USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../japanese/vflib-lib/buildlink.mk"
.include "../vflib-lib/Makefile.common"
