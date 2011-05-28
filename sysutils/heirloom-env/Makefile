# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:24:22 cheusov Exp $

PKGNAME=	heirloom-env-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build env"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
