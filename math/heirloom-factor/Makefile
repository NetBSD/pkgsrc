# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:40:58 cheusov Exp $

PKGNAME=	heirloom-factor-${HEIRLOOM_VER}
CATEGORIES=	math
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build factor"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
