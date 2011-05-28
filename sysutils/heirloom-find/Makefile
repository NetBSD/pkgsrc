# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:17 cheusov Exp $

PKGNAME=	heirloom-find-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build find"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
