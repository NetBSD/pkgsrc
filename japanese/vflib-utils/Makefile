# $NetBSD: Makefile,v 1.3 2001/05/28 03:25:09 jlam Exp $

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}

COMMENT=		Utilities for manipulating VFlib vector font files

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../japanese/vflib-lib/buildlink.mk"
.include "../../japanese/vflib-lib/Makefile.common"
