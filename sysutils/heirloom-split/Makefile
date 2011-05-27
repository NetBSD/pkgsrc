# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:43:12 cheusov Exp $

PKGNAME=	heirloom-split-${HEIRLOOM_VER}
CATEGORIES=	misc sysutils

MAKE_FLAGS+=	SUBDIRS="build split"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
