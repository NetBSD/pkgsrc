# $NetBSD: Makefile,v 1.34 2002/09/20 21:24:48 jlam Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
CATEGORIES+=		x11

COMMENT=		The QT-Enhanced X11 version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib

USE_BUILDLINK2=		# defined
USE_X11=		# defined

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt

ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm			\
	    ${PREFIX}/share/nethackdir${NETHACK_DISTVER}

.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
