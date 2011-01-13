# $NetBSD: Makefile,v 1.58 2011/01/13 13:37:48 wiz Exp $
#

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
PKGREVISION=		10
CATEGORIES+=		x11

MAKE_JOBS_SAFE=		no

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

USE_LANGUAGES=		c c++
BUILD_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt
CFLAGS+=		-DPREFIX="\"${PREFIX}\""

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${DESTDIR}${PREFIX}/share/${NETHACK_DIR}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
