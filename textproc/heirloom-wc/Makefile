# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:24 cheusov Exp $

PKGNAME=	heirloom-wc-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build wc"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
