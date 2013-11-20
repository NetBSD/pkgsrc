# $NetBSD: Makefile,v 1.36 2013/11/20 13:23:43 obache Exp $

DISTNAME=	PokerTH-0.7.1-src
PKGNAME=	pokerth-0.7.1
PKGREVISION=	31
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pokerth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://pokerth.sourceforge.net/
COMMENT=	Texas Holdem poker with online play

USE_TOOLS=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1 share/pokerth \
			share/pixmaps share/applications

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake pokerth.pro ${MAKE_ENV}

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${DESTDIR}${PREFIX}/bin
	${CP} -R ${WRKSRC}/data ${DESTDIR}${PREFIX}/share/pokerth/
	${INSTALL_DATA} ${WRKSRC}/pokerth.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pokerth.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/docs/pokerth.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
