# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:19 cheusov Exp $

PKGNAME=	heirloom-psrinfo-${HEIRLOOM_VER}
CATEGORIES=	sysutils

ONLY_FOR_PLATFORM+=	Linux-*-*

MAKE_FLAGS+=	SUBDIRS="build psrinfo"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
