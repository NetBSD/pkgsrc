# $NetBSD: Makefile,v 1.11 2020/11/05 09:08:13 ryoon Exp $

DISTNAME=	megaglest-3.13.0
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=MegaGlest/}
GITHUB_PROJECT=	megaglest-source
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://megaglest.org/
COMMENT=	3D real-time-strategy game with seven factions
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++03

DEPENDS+=	megaglest-data>=${PKGVERSION_NOREV}:../../games/megaglest-data

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DWANT_GIT_STAMP=OFF
CMAKE_ARGS+=	-DWANT_USE_VLC=OFF
CMAKE_ARGS+=	-DWANT_USE_GoogleBreakpad=OFF
# detection fails; only used by tests?
CMAKE_ARGS+=	-DWANT_USE_FriBiDi=OFF
CMAKE_ARGS+=	-DMEGAGLEST_MANPAGE_INSTALL_PATH="${PKGMANDIR}/man6/"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/ftgl/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
