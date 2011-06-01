# $NetBSD: Makefile,v 1.38 2011/06/01 11:20:30 wiz Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
PKGREVISION=		4
COMMENT=		The X11+tty version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack x11tiles rip.xpm
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc

INSTALLATION_DIRS=	lib/X11/app-defaults lib/X11/fonts/misc

DISTINFO_FILE?=		${.CURDIR}/../nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-x11			\
			    ${GAMEPERM}
post-install:
	${INSTALL_DATA} ${WRKSRC}/dat/x11tiles \
	    ${DESTDIR}${GAMEDIR}
	${INSTALL_DATA} ${WRKSRC}/win/X11/NetHack.ad \
	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/NetHack
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/ibm.bdf \
	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
	    ${DESTDIR}${GAMEDIR}/nethack.x11.rc

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
