# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:47:06 cheusov Exp $

PKGNAME=	heirloom-rmdir-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build rmdir"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
