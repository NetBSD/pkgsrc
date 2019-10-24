# $NetBSD: Makefile,v 1.21 2019/10/24 11:51:52 pho Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

COMMENT=		The tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack
MAKE_ENV+=		GAME=nethack
MAKE_ENV+=		GTYPE=-tty

INSTALLATION_DIRS+=	bin
do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/src/nethack ${DESTDIR}${PREFIX}/bin/nethack-tty

DISTINFO_FILE?=		${.CURDIR}/../../games/nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../../games/nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-tty			\
			    ${GAMEPERM}

.include "../../mk/bsd.pkg.mk"
