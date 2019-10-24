# $NetBSD: Makefile,v 1.28 2019/10/24 11:52:44 pho Exp $

META_PACKAGE=	yes

.include "../../games/nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
CATEGORIES+=	x11

COMMENT=	Meta-package for NetHack with x11, Qt, and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}{,nb*}:../../games/nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}{,nb*}:../../games/nethack-x11

.include "../../mk/bsd.pkg.mk"
