# $NetBSD: Makefile,v 1.19 2002/09/23 10:10:51 jlam Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		the X11 version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_BUILDLINK2=		YES
USE_X11=		YES

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

ALLFILES+=		${DISTFILES}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dat/x11tiles				\
	     ${PREFIX}/share/nethackdir${NETHACK_DISTVER}

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
