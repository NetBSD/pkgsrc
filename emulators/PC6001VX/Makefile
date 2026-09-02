# $NetBSD: Makefile,v 1.127 2026/09/02 19:01:52 wiz Exp $

VERSION=		4.4.0
DISTNAME=		PC6001VX_${VERSION}_src
PKGNAME=		${DISTNAME:S/_src//:S/_/-/}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		https://eighttails.up.seesaa.net/bin/

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://eighttails.seesaa.net/
COMMENT=		Cross platform PC-6001 emulator
LICENSE=		gnu-lgpl-v2.1

TOOL_DEPENDS+=		qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++

INSTALLATION_DIRS+=	bin

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD"
# XXX assumes most major Tier-I ports have HZ=100
CMAKE_CONFIGURE_ARGS+=	-DDELAY_TIMER_MS_DEFAULT=10
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/PC6001VX \
	    ${DESTDIR}${PREFIX}/bin

.include "../../devel/cmake/build.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
