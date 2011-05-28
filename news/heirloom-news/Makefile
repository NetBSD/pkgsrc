# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:16 cheusov Exp $

PKGNAME=	heirloom-news-${HEIRLOOM_VER}
CATEGORIES=	news

MAKE_FLAGS+=	SUBDIRS="build news"

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
