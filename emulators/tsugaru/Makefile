# $NetBSD: Makefile,v 1.1 2026/07/16 11:03:32 nia Exp $

DISTNAME=	tsugaru-20260522
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=captainys/}
GITHUB_PROJECT=	TOWNSEMU
GITHUB_TAG=	v${PKGVERSION_NOREV}

# Should use the most recent commit at the time of when a new release is made.
GITHUB_SUBMODULES+=	captainys public 8cabce7e045b23ad68fdb8592aeacd8d9101e362 gui/src/public

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ysflight.in.coocan.jp/FM/towns/Tsugaru/e.html
COMMENT=	FM Towns emulator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

CMAKE_CONFIGURE_ARGS=	${WRKSRC}/gui/src

CFLAGS.NetBSD+=	-DEBADFD=EBADF
CFLAGS.NetBSD+=	-DESTRPIPE=EPIPE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

pre-build:
	${PREFIX}/bin/magick ${WRKSRC}/src/resources/tsugaru_icon.ico \
		${WRKDIR}/${PKGBASE}.png

.include "../../mk/bsd.fast.prefs.mk"

do-install:
.if ${OPSYS} != "Darwin"
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/main_gui/Tsugaru_GUI \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
.else
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/main_gui/Tsugaru_GUI.app/Contents/MacOS/Tsugaru_GUI \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
.endif
	${INSTALL_DATA} ${WRKDIR}/${PKGBASE}.png \
		${DESTDIR}${PREFIX}/share/pixmaps/${PKGBASE}.png
	${INSTALL_DATA} ${FILESDIR}/${PKGBASE}.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../devel/cmake/build.mk"
.if ${OPSYS} != "Darwin"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../graphics/glu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
