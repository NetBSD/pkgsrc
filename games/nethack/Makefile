# $NetBSD: Makefile,v 1.9 2002/03/13 17:37:02 fredb Exp $

.include	"../nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
PKGREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	Meta-package for NetHack with x11, qt and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}:../nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}:../nethack-x11
DEPENDS+=	nethack-qt-${NETHACK_VERSION}:../nethack-qt

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
