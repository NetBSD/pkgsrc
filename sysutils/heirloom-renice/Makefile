# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:50:11 cheusov Exp $

PKGNAME=	heirloom-renice-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build renice"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
