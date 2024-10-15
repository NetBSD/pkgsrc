# $NetBSD: Makefile,v 1.24 2024/10/15 16:07:01 adam Exp $

PKGNAME=	poppler-qt6-${POPPLER_VERS}
COMMENT=	PDF rendering library (Qt6 wrapper)

CMAKE_CONFIGURE_ARGS+=	-DBUILD_GTK_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GLIB=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTILS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPP=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=ON
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_CONFIGURE_ARGS+=	-DENABLE_LIBCURL=OFF

PKGCONFIG_OVERRIDE+=	poppler-qt6.pc.cmake

INSTALLATION_DIRS+=	lib/pkgconfig

# This must be set before compiler.mk included in Makefile.common.
GCC_REQD+=	9 # required by Qt6 headers
BUILD_DIRS=	qt6/src
.include "../../print/poppler/Makefile.common"

post-install:
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/poppler-qt6.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
