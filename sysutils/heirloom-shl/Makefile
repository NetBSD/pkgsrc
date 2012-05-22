# $NetBSD: Makefile,v 1.2 2012/05/22 16:41:57 marino Exp $

PKGNAME=	heirloom-shl-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build shl"

NOT_FOR_PLATFORM+=	Interix-*-* NetBSD-*-* FreeBSD-*-* OpenBSD-*-*
NOT_FOR_PLATFORM+=	DragonFly-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
