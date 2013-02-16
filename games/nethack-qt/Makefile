# $NetBSD: Makefile,v 1.62 2013/02/16 11:21:24 wiz Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
PKGREVISION=		14
CATEGORIES+=		x11

MAKE_JOBS_SAFE=		no

COMMENT=		The QT-Enhanced X11+tty version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

USE_LANGUAGES=		c c++
BUILD_TARGET=		nethack x11tiles
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt

DISTINFO_FILE?=		${.CURDIR}/../nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-qt			\
			    ${GAMEPERM}
post-install:
	${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${DESTDIR}${GAMEDIR}
	${INSTALL_DATA} ${WRKSRC}/win/Qt/nhsplash.xpm ${DESTDIR}${GAMEDIR}
	${INSTALL_DATA} ${WRKSRC}/win/Qt/knh-mini.xpm ${DESTDIR}${GAMEDIR}
	${INSTALL_DATA} ${WRKSRC}/win/Qt/knh.xpm ${DESTDIR}${GAMEDIR}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
