# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:15:12 cheusov Exp $

PKGNAME=	heirloom-head-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build head"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
