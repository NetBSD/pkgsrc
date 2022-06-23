# $NetBSD: Makefile,v 1.37 2022/06/23 22:18:35 nia Exp $

DISTNAME=	strawberry-1.0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=strawberrymusicplayer/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.strawberrymusicplayer.org/
COMMENT=	Music player and music collection organizer (based on Clementine)
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GCC_REQD+=	7 # std::optional

DEPENDS+=	gst-plugins1-flac-[0-9]*:../../audio/gst-plugins1-flac
DEPENDS+=	gst-plugins1-mpg123-[0-9]*:../../audio/gst-plugins1-mpg123
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-opus-[0-9]*:../../audio/gst-plugins1-opus
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

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
PREFER.sqlite3=	pkgsrc # fts5
# This package will link against libstdc++.so from the pkgsrc GCC when the
# base OS GCC doesn't meet the minimum requirement. Thus we do this so the
# appropriate gcc-libs package will be captured as a dependency, otherwise
# binary packages will be broken.
.  if ${OPSYS_VERSION} < 090000
USE_PKGSRC_GCC=		yes
USE_PKGSRC_GCC_RUNTIME=	yes
.  endif
.endif

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_PORTABILITY_SKIP+=	dist/macos/macversion.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 | ${TRUE}

.include "options.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libxcb/buildlink3.mk"
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.else
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
