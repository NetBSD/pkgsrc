# $NetBSD: Makefile,v 1.20 2011/06/01 11:20:30 wiz Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}
PKGREVISION=		2

COMMENT=		The tty/console based version of NetHack

MAKE_JOBS_SAFE=		no

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

DISTINFO_FILE?=		${.CURDIR}/../nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-tty			\
			    ${GAMEPERM}

.include "../../mk/bsd.pkg.mk"
