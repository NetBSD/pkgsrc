# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:30:56 cheusov Exp $

PKGNAME=	heirloom-more-${HEIRLOOM_VER}
CATEGORIES=	misc sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build more"

NEED_LIBUXRE=	1
NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
