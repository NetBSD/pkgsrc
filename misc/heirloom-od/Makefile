# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:31:15 cheusov Exp $

PKGNAME=	heirloom-od-${HEIRLOOM_VER}
CATEGORIES=	misc

MAKE_FLAGS+=	SUBDIRS="build od"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
