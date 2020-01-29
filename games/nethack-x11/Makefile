# $NetBSD: Makefile,v 1.42 2020/01/29 20:23:16 rhialto Exp $

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		The X11 version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack ${VARDATND}
MAKE_ENV+=		GAME=nethack
MAKE_ENV+=		GTYPE=-x11

VARDATND=		x11tiles NetHack.ad pet_mark.xbm pilemark.xbm rip.xpm
MAKE_ENV+=		VARDATND=${VARDATND:Q}

FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/misc

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/fonts/X11/misc ${HACKDIR}

DISTINFO_FILE?=		${.CURDIR}/../../games/nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../../games/nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-x11			\
			    ${GAMEPERM}
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nethack \
	    ${DESTDIR}${PREFIX}/bin/nethack-x11
	${INSTALL_DATA} ${WRKSRC}/dat/x11tiles \
	    ${DESTDIR}${HACKDIR}
	${INSTALL_DATA} ${WRKSRC}/dat/NetHack.ad \
	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/NetHack
	${INSTALL_DATA} ${WRKSRC}/dat/pet_mark.xbm \
	    ${DESTDIR}${HACKDIR}
	${INSTALL_DATA} ${WRKSRC}/dat/pilemark.xbm \
	    ${DESTDIR}${HACKDIR}
	${INSTALL_DATA} ${WRKSRC}/dat/rip.xpm \
	    ${DESTDIR}${HACKDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/ibm.bdf \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/misc
	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
	    ${DESTDIR}${HACKDIR}/nethack.x11.rc

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
