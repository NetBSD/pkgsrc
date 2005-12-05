# $NetBSD: Makefile,v 1.16 2005/12/05 20:50:17 rillig Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-tty-${NETHACK_VERSION}
PKGREVISION=		1

COMMENT=		The tty/console based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}nb1:../../games/nethack-lib

BUILD_TARGET=		nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-tty

PATCHDIR=		${.CURDIR}/../nethack-lib/patches

.include "../../mk/bsd.pkg.mk"
