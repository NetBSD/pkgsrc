# $NetBSD: Makefile,v 1.11 2014/02/12 23:17:38 tron Exp $
#

.include "Makefile.common"
PKGREVISION=	5

COMMENT=	Command line utility and library to work with mobile phones

# cmake tests for it; unclear for what it would be used
#BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
# for gammu-config
DEPENDS+=	dialog-[0-9]*:../../misc/dialog

USE_CMAKE=	yes
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DINSTALL_MAN_DIR:STRING=${PKGMANDIR}
# see py-gammu:
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF
# make sure some optional dependencies are not found:
CMAKE_ARGS+=	-DWITH_MySQL:BOOL=OFF
CMAKE_ARGS+=	-DWITH_Postgres:BOOL=OFF
CMAKE_ARGS+=	-DWITH_LibDBI:BOOL=OFF
# avoid installing bash completion scripts
CMAKE_ARGS+=	-DBASH_BIN:FILEPATH=
#CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run msgfmt
REPLACE_BASH=	utils/gammu-config utils/jadmaker

# needed because of https://bugs.cihar.com/view.php?id=908
BUILDLINK_TRANSFORM+=	rm:-Werror

LDFLAGS.SunOS+=	-lintl

.include "../../devel/libusb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
