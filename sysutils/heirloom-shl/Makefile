# $NetBSD: Makefile,v 1.3 2025/04/21 21:23:06 wiz Exp $

PKGNAME=	heirloom-shl-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build shl"

NOT_FOR_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*
NOT_FOR_PLATFORM+=	DragonFly-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
