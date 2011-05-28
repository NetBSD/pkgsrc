# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:13:10 cheusov Exp $

PKGNAME=	heirloom-cut-${HEIRLOOM_VER}
CATEGORIES=	textproc

MAKE_FLAGS+=	SUBDIRS="build cut"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
