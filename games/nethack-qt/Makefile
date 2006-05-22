# $NetBSD: Makefile,v 1.51 2006/05/22 22:01:31 wiz Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
PKGREVISION=		6
CATEGORIES+=		x11

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}nb1:../../games/nethack-lib

USE_LANGUAGES=		c c++
BUILD_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt
CFLAGS+=		-DPREFIX="\"${PREFIX}\""

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/${NETHACK_DIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
