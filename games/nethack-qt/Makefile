# $NetBSD: Makefile,v 1.23 2000/10/22 09:21:05 skrll Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-qt-${NETHACK_VERSION}
CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib
DEPENDS+=		qt2-libs-*:../../x11/qt2-libs

USE_X11=		YES
USE_XPM=		YES

ALL_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
EVAL_PREFIX+=		QT2DIR=qt2-libs
PATH=   		${QT2DIR}/qt2/bin:$$PATH
MAKE_ENV+=		GTYPE=-qt QTDIR=${QT2DIR}/qt2

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-install:
	@${CP} -f ${WRKSRC}/dat/x11tiles ${WRKSRC}/dat/tiles.xpm
	@${INSTALL_DATA} ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/nethackdir

.include "../../mk/bsd.pkg.mk"
