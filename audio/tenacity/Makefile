# $NetBSD: Makefile,v 1.3 2026/09/02 19:01:01 wiz Exp $

DISTNAME=		tenacity-v1.3.5
PKGNAME=		${DISTNAME:S/-v/-/}
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_CODEBERG:=tenacityteam/}
CODEBERG_PROJECT=	tenacity
CODEBERG_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://tenacityaudio.org/
COMMENT=	Easy-to-use, cross-platform multi-track audio editor/recorder
LICENSE=	gnu-gpl-v2

CODEBERG_SUBMODULES+=	tenacityteam libnyquist aaf654f44192240170cdb5ed4dc2f004dad2b1e2 lib-src/libnyquist

WRKSRC=			${WRKDIR}/tenacity
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/tenacity

CMAKE_CONFIGURE_ARGS+=	-DPCH=OFF

.include "../../devel/cmake/build.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsbsms/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
