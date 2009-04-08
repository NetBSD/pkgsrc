# $NetBSD: Makefile,v 1.25 2009/04/08 23:02:27 joerg Exp $

META_PACKAGE=	# empty

.include "../../games/nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
PKGREVISION=	3
CATEGORIES+=	x11

COMMENT=	Meta-package for NetHack with x11, qt and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}{,nb*}:../../games/nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}{,nb*}:../../games/nethack-x11
DEPENDS+=	nethack-qt-${NETHACK_VERSION}{,nb*}:../../games/nethack-qt

.include "../../mk/bsd.pkg.mk"
