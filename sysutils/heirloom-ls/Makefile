# $NetBSD: Makefile,v 1.2 2011/05/28 10:15:18 cheusov Exp $

PKGNAME=	heirloom-ls-${HEIRLOOM_VER}
CATEGORIES=	sysutils
LICENSE=	modified-bsd AND original-bsd

MAKE_FLAGS+=	SUBDIRS="build ls"

NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
