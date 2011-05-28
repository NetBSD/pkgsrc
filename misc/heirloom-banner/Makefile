# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:29:52 cheusov Exp $

PKGNAME=	heirloom-banner-${HEIRLOOM_VER}
CATEGORIES=	misc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build banner"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
