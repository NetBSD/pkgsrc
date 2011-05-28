# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 10:01:05 cheusov Exp $

PKGNAME=	heirloom-shl-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build shl"

NOT_FOR_PLATFORM+=	Interix-*-* NetBSD-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
