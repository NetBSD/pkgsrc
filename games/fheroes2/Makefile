# $NetBSD: Makefile,v 1.1 2024/08/19 22:09:32 nia Exp $

DISTNAME=	fheroes2-1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ihhub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ihhub.github.io/fheroes2/
COMMENT=	Recreation of Heroes of Might and Magic II game engine
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
