# $NetBSD: Makefile,v 1.70 2025/10/05 19:25:42 js Exp $

DISTNAME=	qmmp-1.7.4
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://qmmp.ylsoftware.com/files/qmmp/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qmmp.ylsoftware.com/
COMMENT=	Audio player similar to Winamp/XMMS using Qt5
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

# using mpg123 instead, it's better maintained
CMAKE_CONFIGURE_ARGS+=	-DUSE_MAD=OFF

# ??? seems to break playing some files
CMAKE_CONFIGURE_ARGS+=	-DUSE_MPLAYER=OFF

# package not available
CMAKE_CONFIGURE_ARGS+=	-DUSE_PIPEWIRE=OFF

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
PLIST_VARS+=		oss oss4
.  if ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS"
PLIST.oss4=		yes
CMAKE_CONFIGURE_ARGS+=	-DUSE_OSS=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_OSS4=ON
.  else
PLIST.oss=		yes
CMAKE_CONFIGURE_ARGS+=	-DUSE_OSS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_OSS4=OFF
LDFLAGS+=		${LIBOSSAUDIO}
.  endif
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-build
SUBST_MESSAGE.oss=	Correcting the path to OSS device.
SUBST_FILES.oss+=	src/plugins/Output/oss/*
SUBST_FILES.oss+=	src/plugins/Output/oss4/*
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_VARS.oss+=	LIBOSSAUDIO
.endif

QMMP_VER=		${PKGVERSION_NOREV:R}
PLIST_SUBST+=		QMMP_VER=${QMMP_VER}
PRINT_PLIST_AWK+=	{gsub(/qmmp-${QMMP_VER}/, "qmmp-$${QMMP_VER}");}
PRINT_PLIST_AWK+=	/libalsa./ { print "$${PLIST.alsa}" $$0; next }
PRINT_PLIST_AWK+=	/libjack./ { print "$${PLIST.jack}" $$0; next }
PRINT_PLIST_AWK+=	/libpulse./ { print "$${PLIST.pulse}" $$0; next }
PRINT_PLIST_AWK+=	/liboss.so/ { print "$${PLIST.oss}" $$0; next }
PRINT_PLIST_AWK+=	/liboss4.so/ { print "$${PLIST.oss4}" $$0; next }
PRINT_PLIST_AWK+=	/libffmpeg./ { print "$${PLIST.ffmpeg}" $$0; next }

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libwildmidi/buildlink3.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.else
# enable pulseaudio option instead
CMAKE_CONFIGURE_ARGS+=	-DUSE_QTMULTIMEDIA=OFF
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
