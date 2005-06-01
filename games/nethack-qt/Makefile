# $NetBSD: Makefile,v 1.43 2005/06/01 18:02:51 jlam Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
PKGREVISION=		2
CATEGORIES+=		x11

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib


BUILD_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt
CFLAGS+=		-DPREFIX="\"${PREFIX}\""

ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/${NETHACK_DIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
