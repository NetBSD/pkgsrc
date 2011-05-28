# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:24 cheusov Exp $

PKGNAME=	heirloom-ul-${HEIRLOOM_VER}
CATEGORIES=	textproc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build ul"

NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
