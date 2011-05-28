# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:17:06 cheusov Exp $

PKGNAME=	heirloom-pr-${HEIRLOOM_VER}
CATEGORIES=	textproc print
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build pr"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
