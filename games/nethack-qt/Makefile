# $NetBSD: Makefile,v 1.6 1999/04/26 18:38:28 garbled Exp $
#

DISTNAME=		qnethack-3.2.2.1.0.1.src
PKGNAME=		nethack-qt-3.2.2
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.troll.no/contrib/ \
			http://pinky.wtower.com/nethack/sources/
DISTFILES=		qnethack-3.2.2.1.0.1.src.tar.gz \
			nethack-3.2.2.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://trolls.troll.no/warwick/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		qt-1.42:../../x11/qt

WRKSRC=			${WRKDIR}/nethack-3.2.2

USE_X11=		yes
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	sys/unix/setup.sh
ALL_TARGET=		nethack tiles.xpm
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt QTDIR=${X11BASE}

PATCHFILES+=		${PKGSRCDIR}/games/nethack-lib/patches/patch-*
ALLFILES=		${DISTFILES}	# don't checksum shared patches

post-extract:
	@${LN} -sf ../../Qt ${WRKSRC}/win/Qt

post-patch:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/foo
	@${SED} -e 's@XXXLOCALBASEXXX@${LOCALBASE}@g' <${WRKSRC}/foo> ${WRKSRC}/include/config.h
	@${RM} -f ${WRKSRC}/foo
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < win/Qt/nhqt.patch

post-install:
	${INSTALL} -c -o bin -g games -m 0644 ${WRKSRC}/dat/tiles.xpm ${LOCALBASE}/share/nethackdir

.include "../../mk/bsd.pkg.mk"
