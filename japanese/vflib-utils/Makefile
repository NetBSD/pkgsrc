# $NetBSD: Makefile,v 1.2 2001/02/16 15:25:33 wiz Exp $

PKGNAME=		ja-vflib-utils-${VFLIB_VERSION}

COMMENT=		Utilities for manipulating VFlib vector font files

DEPENDS+=		ja-vflib-lib-${VFLIB_VERSION}:../../japanese/vflib-lib

USE_X11=		# defined
CONFIGURE_ARGS+=	--enable-tools --with-x

ALL_TARGET=		build-tools
INSTALL_TARGET=		install-tools

.include "../../japanese/vflib-lib/Makefile.common"
