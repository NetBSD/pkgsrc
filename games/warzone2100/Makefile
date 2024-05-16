# $NetBSD: Makefile,v 1.81 2024/05/16 06:14:57 wiz Exp $

DISTNAME=	warzone2100_src
PKGNAME=	warzone2100-4.4.2
PKGREVISION=	3
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
USE_TOOLS+=	gmake pkg-config zip
USE_TOOLS+=	msgfmt msgmerge xgettext

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

# Needs gnu standard variant to get alloca builtin.
FORCE_CXX_STD=	gnu++14

USE_CXX_FEATURES+=	unique_ptr

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
CMAKE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE=1

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
CFLAGS.Darwin+=		-fobjc-arc
LDFLAGS.DragonFly+=	-lX11 -lintl

BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=		rpath
SUBST_MESSAGE.rpath=	Fixing linker arguments.
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	3rdparty/basis_universal/CMakeLists.txt
SUBST_SED.rpath=	-e 's|-Wl,-rpath |${COMPILER_RPATH_FLAG},|'

# TODO: Patch installation to comply with the common Unix directories and
#       eventually add a variable INSTALL_MACOS_BUNDLE somewhere in mk/
#       to let the possibility to install the bundle in
#       ${LOCALBASE}/Applications/Warzone 2100.app.
# XXX:  It installs out of the box but it does not comply with the pkgsrc
#       directory hierarchy.
.if ${OPSYS} == "Darwin"
PLIST_SRC=	PLIST.bundle
.endif

pre-configure:
	${RUN}${MKDIR} ${WRKSRC}/build

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
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
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
