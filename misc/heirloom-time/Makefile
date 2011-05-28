# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:16 cheusov Exp $

PKGNAME=	heirloom-time-${HEIRLOOM_VER}
CATEGORIES=	misc time

MAKE_FLAGS+=	SUBDIRS="build time"

NOT_FOR_PLATFORM+=	NetBSD-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
