# $NetBSD: Makefile,v 1.23 2024/10/20 14:03:45 wiz Exp $

DISTNAME=	visualboyadvance-m-2.1.4
PKGREVISION=	18
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=visualboyadvance-m/}
GITHUB_PROJECT=	visualboyadvance-m
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://vba-m.com/
COMMENT=	Game Boy and Game Boy Advance emulator (wxWidgets port)
LICENSE=	gnu-gpl-v2

# ASM is i386-only, problems with PIE and others
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ASM=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ASM_SCALERS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LINK=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LTO=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MMX=OFF

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgmerge zip

USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
