# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:20 cheusov Exp $

PKGNAME=	heirloom-split-${HEIRLOOM_VER}
CATEGORIES=	misc sysutils

MAKE_FLAGS+=	SUBDIRS="build split"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
