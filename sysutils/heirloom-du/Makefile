# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:25:08 cheusov Exp $

PKGNAME=	heirloom-du-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build du"

NOT_FOR_PLATFORM+=	Interix-*-*

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
