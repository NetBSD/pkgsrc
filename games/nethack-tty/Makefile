# $NetBSD: Makefile,v 1.11 2001/04/21 13:53:40 wiz Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

COMMENT=		the tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches

.include "../../mk/bsd.pkg.mk"
