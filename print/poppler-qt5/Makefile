# $NetBSD: Makefile,v 1.27 2018/11/12 03:52:49 ryoon Exp $

PKGREVISION= 1
.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt5-${POPPLER_VERS}
COMMENT=		PDF rendering library (QT5 wrapper)
MAINTAINER=		pkgsrc-users@NetBSD.org

CMAKE_ARGS+=    -DENABLE_SPLASH=ON
CMAKE_ARGS+=    -DBUILD_GTK_TESTS=OFF
CMAKE_ARGS+=    -DENABLE_GLIB=OFF
CMAKE_ARGS+=    -DENABLE_UTILS=OFF
CMAKE_ARGS+=    -DENABLE_CPP=OFF
CMAKE_ARGS+=    -DENABLE_QT5=ON
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=    -DENABLE_LIBCURL=OFF

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt5.pc.in

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		qt5/src

pre-build:
	cd ${WRKSRC}/qt5/src && ${BUILD_MAKE_CMD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt5.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
