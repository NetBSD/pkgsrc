# $NetBSD: Makefile,v 1.20 2018/03/12 11:16:26 wiz Exp $

VERSION=		2.32.0
DISTNAME=		PC6001VX_${VERSION}_src
PKGNAME=		${DISTNAME:S/_src//:S/_/-/}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://eighttails.up.seesaa.net/bin/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://eighttails.seesaa.net/
COMMENT=		Cross platform PC-6001 emulator
LICENSE=		gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

INSTALLATION_DIRS+=	bin share/doc/PC6001VX share/doc/PC6001VX/doc

do-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake -o Makefile PC6001VX.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PC6001VX \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.html \
	    ${DESTDIR}${PREFIX}/share/doc/PC6001VX
	cd ${WRKSRC} && pax -rwpp doc \
	    ${DESTDIR}${PREFIX}/share/doc/PC6001VX

.include "../../devel/SDL2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
