# $NetBSD: Makefile,v 1.26 2011/06/01 11:20:29 wiz Exp $

META_PACKAGE=	yes

.include "../../games/nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
PKGREVISION=	3
CATEGORIES+=	x11

COMMENT=	Meta-package for NetHack with x11, Qt, and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}{,nb*}:../../games/nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}{,nb*}:../../games/nethack-x11
DEPENDS+=	nethack-qt-${NETHACK_VERSION}{,nb*}:../../games/nethack-qt

.include "../../mk/bsd.pkg.mk"
