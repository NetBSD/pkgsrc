# $NetBSD: Makefile,v 1.43 2023/09/02 13:45:14 rhialto Exp $

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		The X11 and tty/curses version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack ${VARDATND}
MAKE_ENV+=		GAME=nethack
CONFIGURE_ARGS=		sys/unix/hints/pkgsrc

VARDATND=		x11tiles NetHack.ad pet_mark.xbm pilemark.xbm rip.xpm
MAKE_ENV+=		VARDATND=${VARDATND:Q}

FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/misc

INSTALLATION_DIRS=	bin lib/X11/app-defaults share/fonts/X11/misc ${HACKDIR}

DISTINFO_FILE?=		${.CURDIR}/../../games/nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../../games/nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-x11			\
			    ${GAMEPERM}

pre-configure:
	( ${ECHO} '#-PRE'; \
	  ${ECHO} 'CFLAGS+=-DCURSES_GRAPHICS'; \
	  ${ECHO} 'CURSES_GRAPHICS=1'; \
	  ${ECHO} 'CFLAGS+=-DX11_GRAPHICS'; \
	  ${ECHO} 'X11_GRAPHICS=1'; \
	) > ${WRKSRC}/sys/unix/hints/pkgsrc

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
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
