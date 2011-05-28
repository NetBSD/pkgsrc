# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:15 cheusov Exp $

PKGNAME=	heirloom-cal-${HEIRLOOM_VER}
CATEGORIES=	misc time
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build cal"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
