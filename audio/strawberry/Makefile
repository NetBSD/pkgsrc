# $NetBSD: Makefile,v 1.67 2024/05/29 16:31:25 adam Exp $

DISTNAME=	strawberry-1.0.23
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=strawberrymusicplayer/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.strawberrymusicplayer.org/
COMMENT=	Music player and music collection organizer (based on Clementine)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DBUILD_WITH_QT5=ON
CMAKE_ARGS+=	-DBUILD_WITH_QT6=OFF
CMAKE_ARGS+=	-DUSE_BUNDLE=OFF

DEPENDS+=	gst-plugins1-flac-[0-9]*:../../audio/gst-plugins1-flac
DEPENDS+=	gst-plugins1-mpg123-[0-9]*:../../audio/gst-plugins1-mpg123
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-opus-[0-9]*:../../audio/gst-plugins1-opus
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

USE_CXX_FEATURES+=	c++17

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_ALSA=TRUE
.endif

.if ${OPSYS} != "Linux" && ${OSS_TYPE} != "none"
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.endif

.if ${OPSYS} == "NetBSD"
PREFER.sqlite3=		pkgsrc # fts5
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_PORTABILITY_SKIP+=	dist/macos/macversion.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 || ${TRUE}

.include "options.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libxcb/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
