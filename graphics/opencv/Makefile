# $NetBSD: Makefile,v 1.127 2024/02/09 11:50:30 adam Exp $

PKGREVISION= 2
.include "Makefile.common"

DISTNAME=	opencv-${OPENCV_VERSION}

MAINTAINER=	anthony.mallet@laas.fr
COMMENT=	Library for computer vision problems

INSTALLATION_DIRS+=	share/doc/opencv/papers
INSTALLATION_DIRS+=	share/doc/opencv/ref/pics
INSTALLATION_DIRS+=	share/OpenCV/haarcascades

PKGCONFIG_OVERRIDE+=		build/unix-install/opencv.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	samples/python/*.py

# includes configure output and paths to gmake etc.
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libopencv_core.*

.include "options.mk"

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=	test

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/share/licenses

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
