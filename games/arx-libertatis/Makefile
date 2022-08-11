# $NetBSD: Makefile,v 1.10 2022/08/11 05:08:23 gutteridge Exp $

DISTNAME=	arx-libertatis-1.2
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://arx-libertatis.org/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://arx-libertatis.org/
COMMENT=	Cross-platform, open source port of the Arx Fatalis RPG
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-D CMAKE_INSTALL_MANDIR:STRING:=${PKGMANDIR}
CMAKE_ARGS+=	-D USE_QT4:BOOL=OFF
CMAKE_ARGS+=	-D USE_QT5:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	NotDarwin

.if ${OPSYS} != "Darwin"
PLIST.NotDarwin=	yes
.endif

post-patch:
	${MV} ${WRKSRC}/VERSION ${WRKSRC}/ARX_VERSION

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
