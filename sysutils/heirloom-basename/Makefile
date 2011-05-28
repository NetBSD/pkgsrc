# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:35:46 cheusov Exp $

PKGNAME=	heirloom-basename-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build basename"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
