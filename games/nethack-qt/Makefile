# $NetBSD: Makefile,v 1.1 1998/08/27 13:38:47 garbled Exp $
#

DISTNAME=		qnethack-3.2.2.1.0.1.src
PKGNAME=		nethack-qt-3.2.2
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.troll.no/contrib/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://trolls.troll.no/warwick/nethack/

DEPENDS+=		nethack-lib-3.2.2:../nethack-lib
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		qt-1.40:../../x11/qt

USE_GMAKE=		yes
WRKSRC=			../nethack-lib/work/nethack-3.2.2
ALL_TARGET=		nethack tiles.xpm
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-qt QTDIR=${X11BASE}

do-extract:
	-@mkdir work
	(cd ../nethack-lib && make clean)
	(cd ../nethack-lib && make patch)
	(cd ${WRKSRC}/sys/unix && sh ./setup.sh)
	(cd ${WRKSRC}/src && make clean)
	(cd ${WRKSRC}/win && ${EXTRACT_CMD} -xzf ${DISTDIR}/${DISTNAME}.tar.gz)

post-patch:
	(cd ${WRKSRC} && ${PATCH} -p0 < win/Qt/nhqt.patch)
	(cd ../nethack-lib && make configure)

post-install:
	${INSTALL} -c -o bin -g games -m 0644 ${WRKSRC}/dat/tiles.xpm ${LOCALBASE}/share/nethackdir

do-clean:
	-@rm -r work

.include "../../mk/bsd.pkg.mk"
