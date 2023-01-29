# $NetBSD: Makefile,v 1.78 2023/01/29 21:15:59 ryoon Exp $

VERSION=		4.1.2
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

GCC_REQD+=		9	# for qt6 that requires <filesystem>

INSTALLATION_DIRS+=	bin

.include "options.mk"

do-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${QTDIR}/bin/qmake -o Makefile ${QMAKE_ARGS} PC6001VX.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PC6001VX \
	    ${DESTDIR}${PREFIX}/bin

.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
