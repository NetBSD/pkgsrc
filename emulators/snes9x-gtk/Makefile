# $NetBSD: Makefile,v 1.108 2024/05/29 16:32:27 adam Exp $

PKGREVISION= 4
.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	snes9x-gtk-${SNES9X_VERSION}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) emulator (GUI version)

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt xgettext
USE_TOOLS+=	gawk

USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17

USE_PKGLOCALEDIR=	yes

CMAKE_ARGS+=	-DUSE_SYSTEMZIP=ON
CMAKE_ARGS+=	-DENABLE_PCH=OFF
CMAKE_ARGS+=	-DCMAKE_INSTALL_LOCALEDIR=${PKGLOCALEDIR}/locale

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

CONFIGURE_DIR=	gtk

USE_CXX_FEATURES+=	c++17 filesystem

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	gtk/src/gtk_sound_driver_oss.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
LDFLAGS+=		${LIBOSSAUDIO}
.else
CMAKE_ARGS+=		-DUSE_OSS=OFF
.endif

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
