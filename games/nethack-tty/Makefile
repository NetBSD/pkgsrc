# $NetBSD: Makefile,v 1.19 2009/06/30 00:07:16 joerg Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}
PKGREVISION=		1

COMMENT=		The tty/console based version of NetHack

MAKE_JOBS_SAFE=		no

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

DISTINFO_FILE?=		${.CURDIR}/../nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../nethack-lib/patches

.include "../../mk/bsd.pkg.mk"
