# $NetBSD: Makefile,v 1.71 2022/07/25 01:01:53 tnn Exp $

VERSION=		3.9.0
DISTNAME=		PC6001VX_${VERSION}_src
PKGNAME=		${DISTNAME:S/_src//:S/_/-/}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://eighttails.up.seesaa.net/bin/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://eighttails.seesaa.net/
COMMENT=		Cross platform PC-6001 emulator
LICENSE=		gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

INSTALLATION_DIRS+=	bin

.include "options.mk"

do-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake -o Makefile ${QMAKE_ARGS} PC6001VX.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PC6001VX \
	    ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
