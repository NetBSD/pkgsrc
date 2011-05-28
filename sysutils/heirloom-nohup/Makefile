# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:01:53 cheusov Exp $

PKGNAME=	heirloom-nohup-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build nohup"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
