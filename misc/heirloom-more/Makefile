# $NetBSD: Makefile,v 1.3 2015/08/18 07:31:13 wiz Exp $

PKGNAME=	heirloom-more-${HEIRLOOM_VER}
PKGREVISION=	1
CATEGORIES=	misc sysutils
LICENSE=	original-bsd

MAKE_FLAGS+=	SUBDIRS="build more"

NEED_LIBUXRE=	1
NEED_LIBCURSES=	1

.include "../../sysutils/heirloom-doc/Makefile.common"

DESCR_SRC+=	${.CURDIR}/DESCR

.include "../../devel/heirloom-libcommon/buildlink3.mk"
.include "../../devel/libuxre/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
