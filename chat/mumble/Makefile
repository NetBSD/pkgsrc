# $NetBSD: Makefile,v 1.4 2019/06/22 09:46:58 nia Exp $

DISTNAME=	mumble-1.2.19
PKGREVISION=	1
CATEGORIES=	chat audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mumble-voip/}
GITHUB_PROJECT=	mumble
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.mumble.info/wiki/Main_Page
COMMENT=	Low latency VOIP software
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	boost-headers-[0-9]*:../../devel/boost-headers
DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

# cut down on excessive noise from headers to attempt to make it easier to
# find problems
CXXFLAGS+=	-Wno-deprecated-declarations
CXXFLAGS+=	-Wno-float-conversion
CXXFLAGS+=	-Wno-unused-parameter

BUILDLINK_TRANSFORM+=	rm:-Wconversion
BUILDLINK_TRANSFORM+=	rm:-Wold-style-cast

CONFIG_OPTIONS+=	CONFIG+=no-bundled-opus
CONFIG_OPTIONS+=	CONFIG+=no-bundled-speex

# appears to break the build
CONFIG_OPTIONS+=	CONFIG+=no-embed-qt-translations

# support for an old Logitech keyboard - requires missing library
CONFIG_OPTIONS+=	CONFIG+=no-g15

# requires missing ZeroC utilities
CONFIG_OPTIONS+=	CONFIG+=no-ice

# required by protobuf
CONFIG_OPTIONS+=	CONFIG+=c++11

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	src/mumble/OSS.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

INSTALLATION_DIRS+=	bin lib
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -unix -recursive main.pro \
	    ${CONFIG_OPTIONS} ${MAKE_ENV} \
	    QMAKE_CFLAGS=${CFLAGS:Q} QMAKE_CXXFLAGS=${CXXFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/mumble ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/release/murmurd ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/release/.libs/libcelt0.so.0.11.0 ${DESTDIR}${PREFIX}/lib/libcelt-mumble.so.0.7.0
	${INSTALL_LIB} ${WRKSRC}/release/.libs/libmumble.so.${PKGVERSION_NOREV} ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/scripts/mumble.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.osx.png ${DESTDIR}${PREFIX}/share/icons/hicolor/128x128/apps/mumble.png
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_MAN} ${WRKSRC}/man/mumble.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "options.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
