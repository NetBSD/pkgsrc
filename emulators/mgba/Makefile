# $NetBSD: Makefile,v 1.54 2024/11/14 22:19:42 wiz Exp $

PKGREVISION= 3
.include "Makefile.common"

COMMENT=	Emulator for running Game Boy Advance games (CLI version)

CONFLICTS+=	mgba-qt-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DBUILD_QT=OFF

# XXX: unsure if any of this is useful with the SDL driver
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=OFF

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
