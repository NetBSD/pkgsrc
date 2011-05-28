# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:41:17 cheusov Exp $

PKGNAME=	heirloom-units-${HEIRLOOM_VER}
CATEGORIES=	math
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build units"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
