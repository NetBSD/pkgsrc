# $NetBSD: Makefile,v 1.23 2004/12/03 15:14:57 wiz Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		The X11 version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_BUILDLINK3=		YES
USE_X11=		YES

BUILD_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

ALLFILES+=		${DISTFILES}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dat/x11tiles ${PREFIX}/share/${NETHACK_DIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
