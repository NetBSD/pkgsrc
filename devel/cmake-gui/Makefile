# $NetBSD: Makefile,v 1.69 2026/09/02 19:01:22 wiz Exp $

# BUILD_DIRS
CMAKE_GENERATORS_INCOMPATIBLE=	ninja

PKGREVISION= 1
.include "../../devel/cmake/Makefile.common"

PKGNAME=	cmake-gui-${CMAKE_VERSION}

COMMENT=	CMake GUI

BUILD_DIRS=	Source/QtDialog
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_QtDialog=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_MACOSX_BUNDLE=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMake_QT_MAJOR_VERSION=6
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBARCHIVE=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_CURL=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_EXPAT=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_FORM=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_JSONCPP=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBRHASH=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_USE_SYSTEM_LIBUV=ON

post-build:
	cd ${WRKSRC}/${CMAKE_BUILD_DIR}/bin && \
		${LN} -f -s ${LOCALBASE}/bin/cmake cmake

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.3.3
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
