# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:14:28 cheusov Exp $

PKGNAME=	heirloom-fold-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build fold"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
