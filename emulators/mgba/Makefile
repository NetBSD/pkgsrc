# $NetBSD: Makefile,v 1.48 2024/05/29 16:32:26 adam Exp $

PKGREVISION= 4
.include "Makefile.common"

COMMENT=	Emulator for running Game Boy Advance games (CLI version)

CONFLICTS+=	mgba-qt-[0-9]*

CMAKE_ARGS+=	-DBUILD_QT=OFF

# XXX: unsure if any of this is useful with the SDL driver
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
