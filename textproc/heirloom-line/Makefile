# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:15:50 cheusov Exp $

PKGNAME=	heirloom-line-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build line"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
