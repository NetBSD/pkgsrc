# $NetBSD: Makefile,v 1.8 1999/12/24 22:30:02 pooka Exp $
#

DISTNAME=		nethack-3.3.0
PKGNAME=		nethack-qt-3.3.0
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.win.tue.nl/pub/games/nethack.330/source/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://trolls.troll.no/warwick/nethack/

DEPENDS+=		nethack-lib-3.3.0:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		qt-1.44:../../x11/qt

WRKSRC=			${WRKDIR}/nethack-3.3.0

USE_X11=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	sys/unix/setup.sh
ALL_TARGET=		nethack tiles.xpm
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt QTDIR=${X11BASE}

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

MD5_FILE=		${.CURDIR}/../nethack-lib/files/md5

IGNORE=			"requires qt2 which is unavailable in pkgsrc"

#post-extract:
#	#@${LN} -sf ../../Qt ${WRKSRC}/win/Qt

post-extract:
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo

post-install:
	${INSTALL} -c -o bin -g games -m 0644 ${WRKSRC}/dat/tiles.xpm ${PREFIX}/share/nethackdir

.include "../../mk/bsd.pkg.mk"
