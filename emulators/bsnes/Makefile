# $NetBSD: Makefile,v 1.12 2022/07/02 16:53:14 ryoon Exp $

DISTNAME=	bsnes-115
PKGREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsnes-emu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bsnes-emu/bsnes
COMMENT=	SNES/SFC emulator focused on performance, features, and ease of use
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

# c++17
GCC_REQD+=	7

# incorrect warnings for certain strings with gcc-7.5.0.
CXXFLAGS+=	-Wno-trigraphs

MAKE_FILE=	GNUmakefile

BUILD_DIRS=	bsnes
INSTALL_DIRS=	bsnes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
BUILD_MAKE_FLAGS+=	platform=linux
.elif ${OPSYS} == "Darwin"
BUILD_MAKE_FLAGS+=	platform=macos
.else
BUILD_MAKE_FLAGS+=	platform=bsd
.endif

.if ${OPSYS} != "Darwin"
MAKE_FLAGS+=	hiro=gtk3
.  if ${X11_TYPE} == "native"
LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib
.  endif
.  include "../../mk/oss.buildlink3.mk"
.  if ${OSS_TYPE} != "none"
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	ruby/audio/oss.cpp
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.  endif
.endif

MAKE_FLAGS+=	compiler=${CXX}
MAKE_FLAGS+=	openmp=false
# Disable -march=native.
MAKE_FLAGS+=	local=false

INSTALL_MAKE_FLAGS+=	platform=bsd
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
.if ${OPSYS} != "Darwin"
.  include "../../audio/openal-soft/buildlink3.mk"
.  include "../../devel/SDL2/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../x11/gtk3/buildlink3.mk"
.  include "../../x11/gtksourceview3/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXv/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
