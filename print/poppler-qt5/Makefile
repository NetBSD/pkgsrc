# $NetBSD: Makefile,v 1.79 2024/11/01 00:53:24 wiz Exp $

PKGNAME=	poppler-qt5-${POPPLER_VERS}
PKGREVISION=	1
COMMENT=	PDF rendering library (Qt5 wrapper)

CMAKE_CONFIGURE_ARGS+=	-DBUILD_GTK_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GLIB=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_UTILS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CPP=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT5=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QT6=OFF

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt5.pc.cmake

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=	qt5/src
.include "../../print/poppler/Makefile.common"

zz-pre-build:
	cd ${WRKSRC}/qt5/src && ${BUILD_MAKE_CMD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/poppler-qt5.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
