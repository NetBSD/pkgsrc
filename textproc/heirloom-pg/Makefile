# $NetBSD: Makefile,v 1.1.1.1 2011/05/28 08:16:47 cheusov Exp $

PKGNAME=	heirloom-pg-${HEIRLOOM_VER}
CATEGORIES=	textproc print

MAKE_FLAGS+=	SUBDIRS="build pg"

NEED_LIBUXRE=	1
NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
