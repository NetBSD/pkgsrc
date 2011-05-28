# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:18:50 cheusov Exp $

PKGNAME=	heirloom-ul-${HEIRLOOM_VER}
CATEGORIES=	textproc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build ul"

NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
