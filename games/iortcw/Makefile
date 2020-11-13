# $NetBSD: Makefile,v 1.10 2020/11/13 16:17:06 nia Exp $

DISTNAME=	iortcw-1.51c
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=iortcw/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/iortcw/iortcw
COMMENT=	Game engine for Return to Castle Wolfenstein
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

BUILD_DIRS=	SP MP
BUILD_TARGET=	release
INSTALL_DIRS=	SP MP
INSTALL_TARGET=	copyfiles

MAKE_FLAGS+=	V=1
MAKE_FLAGS+=	BUILD_SERVER=1
MAKE_FLAGS+=	BUILD_CLIENT=1
MAKE_FLAGS+=	BUILD_GAME_SO=1
MAKE_FLAGS+=	BUILD_GAME_QVM=0
MAKE_FLAGS+=	USE_RENDERER_DLOPEN=0
MAKE_FLAGS+=	CROSS_COMPILING=0
MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CXX=${CXX:Q}
MAKE_FLAGS+=	TOOLS_CC=${CC:Q}
MAKE_FLAGS+=	BUILD_BASEGAME=1
MAKE_FLAGS+=	USE_OPENAL=1
MAKE_FLAGS+=	USE_OPENAL_DLOPEN=0
MAKE_FLAGS+=	USE_CURL=1
MAKE_FLAGS+=	USE_CURL_DLOPEN=0
MAKE_FLAGS+=	USE_CODEC_VORBIS=1
MAKE_FLAGS+=	USE_CODEC_OPUS=1
MAKE_FLAGS+=	USE_FREETYPE=1
MAKE_FLAGS+=	USE_INTERNAL_LIBS=0
MAKE_FLAGS+=	USE_LOCAL_HEADERS=0
MAKE_FLAGS+=	OPTIMIZEVM=""
MAKE_FLAGS+=	OPTIMIZE=""
MAKE_FLAGS+=	COPYDIR="${DESTDIR}${PREFIX}/share/iortcw"

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=	COMPILE_ARCH=${MACHINE_ARCH}

.if ${MACHINE_ARCH} == "i386"
IORTCW_ARCH=	x86
.elif ${MACHINE_ARCH} == "x86_64"
IORTCW_ARCH=	x86_64
.elif !empty(MACHINE_ARCH:Mpowerpc64*)
IORTCW_ARCH=	ppc64
.elif ${MACHINE_ARCH} == "sparc64"
IORTCW_ARCH=	sparc
.else
IORTCW_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	IORTCW_ARCH=${IORTCW_ARCH}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps

CHECK_PORTABILITY_SKIP+=	SP/make-macosx_xcode3.sh
CHECK_PORTABILITY_SKIP+=	SP/make-macosx_xcode4.sh
CHECK_PORTABILITY_SKIP+=	SP/make-macosx_xcode5.sh
CHECK_PORTABILITY_SKIP+=	MP/make-macosx_xcode3.sh
CHECK_PORTABILITY_SKIP+=	MP/make-macosx_xcode4.sh
CHECK_PORTABILITY_SKIP+=	MP/make-macosx_xcode5.sh

post-build:
.for bin in iowolfded iowolfmp iowolfsp
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@WOLFBIN@,${PREFIX}/share/iortcw/${bin}.${IORTCW_ARCH},g' \
		${FILESDIR}/iortcw.sh.in > ${WRKDIR}/${bin}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfded ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfmp ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/iowolfsp ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/iowolfmp.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/iowolfsp.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/MP/misc/iortcw.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wolfmp.svg
	${INSTALL_DATA} ${WRKSRC}/SP/misc/iortcw.svg \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/wolfsp.svg

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
