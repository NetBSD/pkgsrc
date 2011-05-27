# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:52:03 cheusov Exp $

PKGNAME=	heirloom-psrinfo-${HEIRLOOM_VER}
CATEGORIES=	sysutils

ONLY_FOR_PLATFORM+=	Linux-*-*

MAKE_FLAGS+=	SUBDIRS="build psrinfo"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
