# $NetBSD: Makefile,v 1.12 2003/07/21 16:49:57 martti Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}

COMMENT=		The tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

ALL_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches

.include "../../mk/bsd.pkg.mk"
