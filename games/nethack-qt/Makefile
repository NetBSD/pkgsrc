# $NetBSD: Makefile,v 1.25 2001/06/26 18:52:09 jlam Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
CATEGORIES+=		x11

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_X11=		YES

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/nethackdir

.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
