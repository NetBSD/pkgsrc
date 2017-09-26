# $NetBSD: Makefile,v 1.27 2017/09/26 21:43:37 wiz Exp $

META_PACKAGE=	yes

.include "../../games/nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
PKGREVISION=	4
CATEGORIES+=	x11

COMMENT=	Meta-package for NetHack with x11, Qt, and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}{,nb*}:../../games/nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}{,nb*}:../../games/nethack-x11

.include "../../mk/bsd.pkg.mk"
