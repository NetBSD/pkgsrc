# $NetBSD: Makefile,v 1.3 2015/08/18 07:31:17 wiz Exp $

PKGNAME=	heirloom-ls-${HEIRLOOM_VER}
PKGREVISION=	1
CATEGORIES=	sysutils
LICENSE=	modified-bsd AND original-bsd

MAKE_FLAGS+=	SUBDIRS="build ls"

NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
