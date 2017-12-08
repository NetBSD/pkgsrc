# $NetBSD: Makefile,v 1.49 2017/12/08 07:48:12 spz Exp $

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt4-${POPPLER_VERS}
COMMENT=		PDF rendering library (QT4 wrapper)
MAINTAINER=		reed@reedmedia.net

CMAKE_ARGS+=    -DENABLE_SPLASH=ON
CMAKE_ARGS+=    -DCMAKE_DISABLE_FIND_PACKAGE_CAIRO=TRUE
CMAKE_ARGS+=    -DBUILD_GTK_TESTS=OFF
CMAKE_ARGS+=    -DENABLE_GLIB=OFF
CMAKE_ARGS+=    -DENABLE_UTILS=OFF
CMAKE_ARGS+=    -DENABLE_CPP=OFF
CMAKE_ARGS+=    -DENABLE_QT4=ON
CMAKE_ARGS+=    -DENABLE_QT5=OFF
# Don't build libcurl based HTTP support. ## might want to include
CMAKE_ARGS+=    -DENABLE_LIBCURL=OFF

CMAKE_ARGS+=	-DMOCQT4=${QTDIR}/bin/moc

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt4.pc.in

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		qt4/src

pre-build:
	cd ${WRKSRC}/qt4/src && ${BUILD_MAKE_CMD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_DEPMETHOD.qt4-tools?=	full

BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.7.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
