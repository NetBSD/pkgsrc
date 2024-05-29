# $NetBSD: Makefile,v 1.18 2024/05/29 16:32:27 adam Exp $

PKGREVISION= 5
.include "${.CURDIR}/../../emulators/mgba/Makefile.common"

PKGNAME=	${DISTNAME:S/mgba-/mgba-qt-/g}
COMMENT=	Emulator for running Game Boy Advance games (GUI version)

CONFLICTS+=	mgba-[0-9]*

CMAKE_ARGS+=	-DBUILD_QT=ON

# performance problems...
CMAKE_ARGS+=	-DBUILD_GL=OFF
CMAKE_ARGS+=	-DBUILD_GLES2=OFF
CMAKE_ARGS+=	-DBUILD_GLES3=OFF
CMAKE_ARGS+=	-DUSE_EPOXY=OFF

USE_CXX_FEATURES+=	c++14

# We probably don't actually want Qt5Multimedia.
# It's an option as an audio output, but SDL supports many more pkgsrc
# platforms natively, without going via PulseAudio.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Multimedia=TRUE

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
