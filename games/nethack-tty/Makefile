# $NetBSD: Makefile,v 1.10 2001/02/16 15:10:55 wiz Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

COMMENT=		the tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches
PATCH_SUM_FILE=		${.CURDIR}/../nethack-lib/files/patch-sum

.include "../../mk/bsd.pkg.mk"
