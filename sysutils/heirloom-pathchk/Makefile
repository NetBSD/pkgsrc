# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:00:29 cheusov Exp $

PKGNAME=	heirloom-pathchk-${HEIRLOOM_VER}
CATEGORIES=	sysutils misc

MAKE_FLAGS+=	SUBDIRS="build pathchk"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
