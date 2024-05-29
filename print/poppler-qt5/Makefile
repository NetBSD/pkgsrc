# $NetBSD: Makefile,v 1.76 2024/05/29 16:34:11 adam Exp $

PKGREVISION= 3
.include "../../print/poppler/Makefile.common"

PKGNAME=	poppler-qt5-${POPPLER_VERS}
COMMENT=	PDF rendering library (QT5 wrapper)
MAINTAINER=	pkgsrc-users@NetBSD.org

CMAKE_ARGS+=	-DBUILD_GTK_TESTS=OFF
CMAKE_ARGS+=	-DENABLE_GLIB=OFF
CMAKE_ARGS+=	-DENABLE_UTILS=OFF
CMAKE_ARGS+=	-DENABLE_CPP=OFF
CMAKE_ARGS+=	-DENABLE_QT5=ON
CMAKE_ARGS+=	-DENABLE_QT6=OFF
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=	-DENABLE_LIBCURL=OFF

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt5.pc.cmake

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		qt5/src

pre-build:
	cd ${WRKSRC}/qt5/src && ${BUILD_MAKE_CMD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt5.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
