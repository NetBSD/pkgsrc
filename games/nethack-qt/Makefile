# $NetBSD: Makefile,v 1.39 2004/10/03 00:14:46 tv Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
PKGREVISION=		2
CATEGORIES+=		x11

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_BUILDLINK3=		yes
USE_X11=		# defined

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt
CFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"

ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/${NETHACK_DIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
