# $NetBSD: Makefile,v 1.12 2017/09/16 17:10:19 tsutsui Exp $

VERSION=		2.31.1
DISTNAME=		PC6001VX_${VERSION}_src
PKGNAME=		${DISTNAME:S/_src//:S/_/-/}
CATEGORIES=		emulators
MASTER_SITES=		http://eighttails.up.seesaa.net/bin/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://eighttails.seesaa.net/
COMMENT=		Cross platform PC-6001 emulator
LICENSE=		gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

INSTALLATION_DIRS+=	bin share/doc/PC6001VX

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile PC6001VX.pro

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${WRKSRC}/PC6001VX \
	    ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} ${WRKSRC}/README.html \
	    ${DESTDIR}${PREFIX}/share/doc/PC6001VX

.include "../../devel/SDL2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
