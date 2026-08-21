# $NetBSD: Makefile,v 1.70 2026/08/21 11:52:39 adam Exp $

DISTNAME=	Gammu-1.44.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=gammu/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wammu.eu/gammu/
COMMENT=	Command line utility and library to work with mobile phones
LICENSE=	gnu-gpl-v2

# cmake tests for it; unclear for what it would be used
#TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
# for gammu-config
DEPENDS+=	dialog-[0-9]*:../../misc/dialog

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_MAN_DIR:STRING=${PKGMANDIR}
# make sure some optional dependencies are not found:
CMAKE_CONFIGURE_ARGS+=	-DWITH_MySQL:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_Postgres:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_LibDBI:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_Glib:BOOL=OFF
# avoid installing bash completion scripts
CMAKE_CONFIGURE_ARGS+=	-DBASH_BIN:FILEPATH=

# silence warning
CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_DOC=ON

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run msgfmt

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/libgammu
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/libgammu

REPLACE_BASH=	utils/gammu-config utils/jadmaker

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int32_t=uint32_t

# needed because of https://bugs.cihar.com/view.php?id=908
BUILDLINK_TRANSFORM+=	rm:-Werror

SUBST_CLASSES+=			cmakelists
SUBST_STAGE.cmakelists=		pre-configure
SUBST_MESSAGE.cmakelists=	Fixing CMakeLists.txt
SUBST_FILES.cmakelists=		CMakeLists.txt
SUBST_SED.cmakelists=		-e 's/LIB_SUFFIX "64"/LIB_SUFFIX ""/'

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
