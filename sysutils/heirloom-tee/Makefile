# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:38:07 cheusov Exp $

PKGNAME=	heirloom-tee-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build tee"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
