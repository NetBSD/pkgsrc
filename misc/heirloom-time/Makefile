# $NetBSD: Makefile,v 1.3 2012/05/22 17:18:21 marino Exp $

PKGNAME=	heirloom-time-${HEIRLOOM_VER}
CATEGORIES=	misc time

MAKE_FLAGS+=	SUBDIRS="build time"

ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
