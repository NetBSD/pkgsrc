# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:14 cheusov Exp $

PKGNAME=	heirloom-factor-${HEIRLOOM_VER}
CATEGORIES=	math
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build factor"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
