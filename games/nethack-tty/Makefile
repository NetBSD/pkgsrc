# $NetBSD: Makefile,v 1.9 2000/10/16 01:37:51 wiz Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches
PATCH_SUM_FILE=		${.CURDIR}/../nethack-lib/files/patch-sum

.include "../../mk/bsd.pkg.mk"
