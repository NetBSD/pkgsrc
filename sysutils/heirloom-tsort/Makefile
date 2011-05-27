# $NetBSD: Makefile,v 1.1.1.1 2011/05/27 23:36:12 cheusov Exp $

PKGNAME=	heirloom-tsort-${HEIRLOOM_VER}
CATEGORIES=	sysutils misc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build tsort"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
