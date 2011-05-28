# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:33:10 cheusov Exp $

PKGNAME=	heirloom-chown-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build chown"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
