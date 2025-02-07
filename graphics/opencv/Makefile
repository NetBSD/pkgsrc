# $NetBSD: Makefile,v 1.140 2025/02/07 21:54:16 wiz Exp $

.include "Makefile.common"

DISTNAME=	opencv-${OPENCV_VERSION}

MAINTAINER=	anthony.mallet@laas.fr
COMMENT=	Library for computer vision problems

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	samples/python/*.py

.include "options.mk"

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=	test

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/licenses/opencv4 ${DESTDIR}${PREFIX}/share/opencv4/licenses

.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=2.3.1
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
