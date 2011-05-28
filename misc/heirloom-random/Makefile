# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 09:52:50 cheusov Exp $

PKGNAME=	heirloom-random-${HEIRLOOM_VER}
CATEGORIES=	misc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build random"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
