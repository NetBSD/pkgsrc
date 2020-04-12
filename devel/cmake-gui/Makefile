# $NetBSD: Makefile,v 1.8 2020/04/12 08:28:29 adam Exp $

PKGREVISION= 1
.include "../../devel/cmake/Makefile.common"

PKGNAME=	cmake-gui-${CMAKE_VERSION}

COMMENT=	CMake GUI

USE_CMAKE=	yes
BUILD_DIRS=	Source/QtDialog
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DBUILD_QtDialog=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBARCHIVE=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_CURL=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_EXPAT=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_FORM=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_JSONCPP=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBRHASH=ON
CMAKE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBUV=ON

post-build:
	cd ${WRKSRC}/bin && ${LN} -f -s ${CMAKE} cmake

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.3.3
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
