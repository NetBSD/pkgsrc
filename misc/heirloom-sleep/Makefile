# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:31:54 cheusov Exp $

PKGNAME=	heirloom-sleep-${HEIRLOOM_VER}
CATEGORIES=	misc

MAKE_FLAGS+=	SUBDIRS="build sleep"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
