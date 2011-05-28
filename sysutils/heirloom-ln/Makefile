# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:14:20 cheusov Exp $

PKGNAME=	heirloom-ln-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build ln"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
