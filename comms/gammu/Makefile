# $NetBSD: Makefile,v 1.2 2009/05/26 21:31:21 wiz Exp $
#

.include "Makefile.common"

COMMENT=	Command line utility and library to work with mobile phones
PKGREVISION=	1

# cmake tests for it; unclear for what it would be used
#BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
# for gammu-config
DEPENDS+=	dialog-[0-9]*:../../misc/dialog

PKG_DESTDIR_SUPPORT=	user-destdir

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

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
REPLACE_BASH=	utils/gammu-config utils/jadmaker

# needed because of https://bugs.cihar.com/view.php?id=908
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/libusb/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
