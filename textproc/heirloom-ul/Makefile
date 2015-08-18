# $NetBSD: Makefile,v 1.3 2015/08/18 07:31:19 wiz Exp $

PKGNAME=	heirloom-ul-${HEIRLOOM_VER}
PKGREVISION=	1
CATEGORIES=	textproc
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build ul"

NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
