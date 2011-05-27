# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:26:21 cheusov Exp $

PKGNAME=	heirloom-whodo-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build whodo"

NEED_LIBKVM=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
