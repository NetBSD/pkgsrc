# $NetBSD: Makefile,v 1.23 2007/10/25 22:00:44 jlam Exp $

# Needed so configure/patch rules don't get pulled in
NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../games/nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
PKGREVISION=	3
CATEGORIES+=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	Meta-package for NetHack with x11, qt and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}{,nb*}:../../games/nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}{,nb*}:../../games/nethack-x11
DEPENDS+=	nethack-qt-${NETHACK_VERSION}{,nb*}:../../games/nethack-qt

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
PLIST_SRC=	# empty (meta-package)

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
