# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:57:07 cheusov Exp $

PKGNAME=	heirloom-priocntl-${HEIRLOOM_VER}
CATEGORIES=	sysutils

ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*

MAKE_FLAGS+=		SUBDIRS="build priocntl"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
