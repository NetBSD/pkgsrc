# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 00:28:44 cheusov Exp $

PKGNAME=	heirloom-csplit-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAKE_FLAGS+=	SUBDIRS="build csplit"

NEED_LIBUXRE=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
