# $NetBSD: Makefile,v 1.22 2023/09/02 13:45:14 rhialto Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

COMMENT=		The tty and curses based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack
CONFIGURE_ARGS=		sys/unix/hints/pkgsrc
MAKE_ENV+=		GAME=nethack

pre-configure:
	( ${ECHO} '#-PRE'; \
	  ${ECHO} 'CFLAGS+=-DCURSES_GRAPHICS'; \
	  ${ECHO} 'CURSES_GRAPHICS=1'; \
	) > ${WRKSRC}/sys/unix/hints/pkgsrc

INSTALLATION_DIRS+=	bin
do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/src/nethack ${DESTDIR}${PREFIX}/bin/nethack-tty

DISTINFO_FILE?=		${.CURDIR}/../../games/nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../../games/nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-tty			\
			    ${GAMEPERM}

.include "../../mk/bsd.pkg.mk"
