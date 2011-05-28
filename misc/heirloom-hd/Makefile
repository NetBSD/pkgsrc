# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 09:40:41 cheusov Exp $

PKGNAME=	heirloom-hd-${HEIRLOOM_VER}
CATEGORIES=	misc sysutils

MAKE_FLAGS+=	SUBDIRS="build hd"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
