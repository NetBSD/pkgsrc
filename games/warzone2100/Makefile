# $NetBSD: Makefile,v 1.61 2022/07/02 16:53:21 ryoon Exp $

DISTNAME=	warzone2100_src
PKGNAME=	warzone2100-4.2.7
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Warzone2100/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
DIST_SUBDIR=	wz2100_${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wz2100.net/
COMMENT=	Real-time strategy and real-time tactics hybrid computer game
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config zip
USE_TOOLS+=	msgfmt msgmerge xgettext

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Could NOT find Gettext: Found unsuitable version "0.16.1", but
# required is at least "0.18"
TOOLS_PLATFORM.msgfmt=
TOOLS_PLATFORM.msgmerge=
TOOLS_PLATFORM.xgettext=
.endif

.include "../../games/warzone2100/options.mk"

WRKSRC=		${WRKDIR}/warzone2100
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=		-DCMAKE_MAKE_PROGRAM=${MAKE_PROGRAM} -DWZ_DISTRIBUTOR=pkgsrc

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
LDFLAGS.DragonFly+=	-lX11 -lintl

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	${RUN}${MKDIR} ${WRKSRC}/build

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.gettext+=		gettext>=0.18
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.10.2
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glew+=		glew>=1.5.2
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsodium+=	libsodium>=1.0.13
.include "../../security/libsodium/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
