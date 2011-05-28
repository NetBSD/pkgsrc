# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:38:09 cheusov Exp $

PKGNAME=	heirloom-news-${HEIRLOOM_VER}
CATEGORIES=	news

MAKE_FLAGS+=	SUBDIRS="build news"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
