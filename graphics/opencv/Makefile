# $NetBSD: Makefile,v 1.93 2020/08/03 22:37:05 joerg Exp $

.include "Makefile.common"

DISTNAME=	opencv-${OPENCV_VERSION}
PKGREVISION=	4

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

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/lib
TEST_TARGET=	test

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/share/licenses

.include "../../mk/bsd.prefs.mk"

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
