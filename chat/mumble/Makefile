# $NetBSD: Makefile,v 1.64 2024/05/29 16:31:31 adam Exp $

DISTNAME=	mumble-1.4.287
PKGREVISION=	3
CATEGORIES=	chat audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mumble-voip/}
GITHUB_PROJECT=	mumble
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.mumble.info/wiki/Main_Page
COMMENT=	Low latency VOIP software
LICENSE=	modified-bsd

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

WRKSRC=		${WRKDIR}/mumble-${PKGVERSION_NOREV}.src

# NetBSD make not suitable due to targets with spaces
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

USE_CXX_FEATURES+=	c++11

LDFLAGS.NetBSD+=	-lrt

# Basic sensible stuff for packaging.
# Requires 0.7.x, pkgsrc version is too new
#CMAKE_ARGS+=	-Dbundled-celt=off
CMAKE_ARGS+=	-Dbundled-opus=off
CMAKE_ARGS+=	-Dbundled-speex=off
CMAKE_ARGS+=	-Dwarnings-as-errors=off

# Compatibility.
CXXFLAGS+=	-DCELT_SET_VBR_RATE=CELT_SET_BITRATE

# Architecture-specific due to nasty hacks...
CMAKE_ARGS+=	-Doverlay=off

# Not available in pkgsrc yet.
CMAKE_ARGS+=	-Dpipewire=off

# support for an old Logitech keyboard - requires missing library
CMAKE_ARGS+=	-Dg15=off

# requires missing ZeroC utilities
CMAKE_ARGS+=	-Dice=off

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LDFLAGS+=	${LIBOSSAUDIO}
CMAKE_ARGS+=	-Doss=on
.else
CMAKE_ARGS+=	-Doss=off
.endif

CHECK_PORTABILITY_SKIP+=	3rdparty/opus-src/doc/build_draft.sh

.include "options.mk"
# Requires 0.7.x, pkgsrc version is too new
#.include "../../audio/celt/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/poco/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
