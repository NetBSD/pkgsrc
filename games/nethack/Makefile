# $NetBSD: Makefile,v 1.16 2005/06/01 18:02:51 jlam Exp $

# Needed so configure/patch rules don't get pulled in
NO_BUILD=	yes
NO_CONFIGURE=	yes

.include	"../nethack-lib/Makefile.common"

DISTNAME=	nethack-all-${NETHACK_VERSION}
CATEGORIES+=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	Meta-package for NetHack with x11, qt and tty versions

DEPENDS+=	nethack-tty-${NETHACK_VERSION}:../nethack-tty
DEPENDS+=	nethack-x11-${NETHACK_VERSION}:../nethack-x11
DEPENDS+=	nethack-qt-${NETHACK_VERSION}nb2:../nethack-qt

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes

do-install:	# empty
do-patch:	# empty

.include "../../mk/bsd.pkg.mk"
