# $NetBSD: Makefile,v 1.18 2002/03/25 20:32:29 pooka Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		the X11 version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_BUILDLINK_ONLY=	YES

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

ALLFILES+=		${DISTFILES}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dat/x11tiles				\
	     ${PREFIX}/share/nethackdir${NETHACK_DISTVER}

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
